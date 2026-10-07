"""
CodeChef statistics provider using embedded structured Drupal state and browser fallback.
"""

import json
import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional, List
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


CODECHEF_HEADERS = {
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8",
}


def fetch_codechef_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch CodeChef statistics using embedded structured data (Drupal.settings) and HTML parsing,
    with browser rendering fallback.
    """
    metrics: Dict[str, Any] = {}
    errors: List[str] = []

    # 1. Primary: Direct fetch of HTML with embedded Drupal.settings JSON
    _fetch_codechef_html(profile_url, metrics, errors)

    # 2. Browser fallback if rating or solved is missing
    if "rating" not in metrics or "solved" not in metrics:
        try:
            from .browser_renderer import is_playwright_available
            if is_playwright_available():
                _fetch_codechef_browser(profile_url, metrics)
        except Exception as e:
            errors.append(f"Browser fallback error: {str(e)}")

    # Determine status
    if "rating" in metrics:
        status = RetrievalStatus.SUCCESS
        error = None
    elif metrics:
        status = RetrievalStatus.PARTIAL
        error = "; ".join(errors) if errors else "Retrieved partial CodeChef statistics"
    else:
        status = RetrievalStatus.UNAVAILABLE
        error = "; ".join(errors) if errors else "Could not retrieve statistics from CodeChef"

    return PlatformStats(
        platform="CodeChef",
        username=username,
        profile_url=profile_url,
        metrics=metrics,
        status=status,
        source="public_profile",
        source_type="live",
        retrieval_method="embedded_state",
        retrieved_at=datetime.now(timezone.utc).isoformat(),
        error=error,
    )


def _fetch_codechef_html(profile_url: str, metrics: Dict[str, Any], errors: List[str]):
    """Fetch HTML and parse Drupal.settings JSON and semantic markup."""
    try:
        req = urllib.request.Request(profile_url, headers=CODECHEF_HEADERS)
        with urllib.request.urlopen(req, timeout=12) as resp:
            html = resp.read().decode("utf-8", errors="ignore")

        # 1. Parse embedded Drupal.settings JSON
        m_drupal = re.search(r"jQuery\.extend\(Drupal\.settings,\s*({.+?})\);", html, re.DOTALL)
        if m_drupal:
            try:
                drupal_data = json.loads(m_drupal.group(1))
                dvr = drupal_data.get("date_versus_rating", {})

                # Contest rating history
                all_ratings = dvr.get("all", [])
                if all_ratings:
                    latest_all = all_ratings[-1]
                    try:
                        metrics["rating"] = int(latest_all.get("rating"))
                    except (ValueError, TypeError):
                        pass
                    try:
                        metrics["global_rank"] = int(latest_all.get("rank"))
                    except (ValueError, TypeError):
                        pass

                    # Calculate max rating from history
                    max_r = 0
                    for entry in all_ratings:
                        try:
                            r_val = int(entry.get("rating"))
                            if r_val > max_r:
                                max_r = r_val
                        except (ValueError, TypeError):
                            pass
                    if max_r > 0:
                        metrics["max_rating"] = max_r

                # DSA Monday contest ratings
                dsa_ratings = dvr.get("dsa_monday", [])
                if dsa_ratings:
                    latest_dsa = dsa_ratings[-1]
                    try:
                        metrics["dsa_rating"] = int(latest_dsa.get("rating"))
                    except (ValueError, TypeError):
                        pass
                    try:
                        metrics["dsa_global_rank"] = int(latest_dsa.get("rank"))
                    except (ValueError, TypeError):
                        pass
            except Exception as e:
                errors.append(f"Drupal settings JSON parse error: {str(e)}")

        # 2. Total problems solved
        m_solved = re.search(r"Total Problems Solved:\s*(\d+)", html, re.IGNORECASE)
        if m_solved:
            metrics["solved"] = int(m_solved.group(1))

        # 3. Stars / Division
        m_stars = re.search(r"(\d+)&#9733;", html)
        if m_stars:
            metrics["stars"] = int(m_stars.group(1))
        else:
            m_star_text = re.search(r"(\d+)\s*★", html)
            if m_star_text:
                metrics["stars"] = int(m_star_text.group(1))

        # 4. League (Silver, Diamond, Gold, etc.)
        m_league = re.search(r"alt=[\"']([^\"']*League)[\"']", html, re.IGNORECASE)
        if m_league:
            metrics["league"] = m_league.group(1)

        # 5. Fallback for rating if Drupal.settings didn't yield it
        if "rating" not in metrics:
            m_rating = re.search(r'class="rating"[^>]*>(\d+)', html)
            if m_rating:
                metrics["rating"] = int(m_rating.group(1))

        # 6. Fallback for highest rating
        if "max_rating" not in metrics:
            m_max = re.search(r"Highest Rating\s*(\d+)", html, re.IGNORECASE)
            if m_max:
                metrics["max_rating"] = int(m_max.group(1))

    except Exception as e:
        errors.append(f"HTTP fetch error: {str(e)}")


def _fetch_codechef_browser(profile_url: str, metrics: Dict[str, Any]):
    """Browser rendering fallback via Playwright."""
    import asyncio
    from .browser_renderer import fetch_rendered_page

    async def _fetch():
        page_data = await fetch_rendered_page(profile_url, wait_timeout=20000, capture_network=False)
        text = page_data.get("text", "")
        if not text:
            return

        if "rating" not in metrics:
            m_r = re.search(r"(\d{3,4})\s*rating", text, re.IGNORECASE)
            if m_r:
                metrics["rating"] = int(m_r.group(1))

        if "solved" not in metrics:
            m_s = re.search(r"Total Problems Solved:\s*(\d+)", text, re.IGNORECASE)
            if m_s:
                metrics["solved"] = int(m_s.group(1))

    try:
        asyncio.run(_fetch())
    except Exception:
        pass
