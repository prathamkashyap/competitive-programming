"""
HackerEarth statistics provider using public REST API and browser rendering.
"""

import json
import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional, List
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


HACKEREARTH_HEADERS = {
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Accept": "application/json, text/plain, */*",
}


def fetch_hackerearth_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch HackerEarth statistics using public endpoints and browser rendering fallback.
    """
    metrics: Dict[str, Any] = {}
    errors: List[str] = []

    # 1. Primary: Fetch from public JSON API
    api_success = _fetch_hackerearth_api(username, metrics, errors)

    # 2. Supplementary / Browser inspection: Get track rankings & stars
    try:
        from .browser_renderer import is_playwright_available
        if is_playwright_available():
            _fetch_hackerearth_browser(username, profile_url, metrics)
    except Exception:
        pass

    # Determine status
    if "points" in metrics and "solved" in metrics:
        status = RetrievalStatus.SUCCESS
        error = None
    elif metrics:
        status = RetrievalStatus.PARTIAL
        error = "; ".join(errors) if errors else "Retrieved partial HackerEarth statistics"
    else:
        status = RetrievalStatus.UNAVAILABLE
        error = "; ".join(errors) if errors else "Could not retrieve statistics from HackerEarth"

    retrieval_method = "api_and_rendered" if ("basic_programming_rank" in metrics or "top_percentiles" in metrics) else "public_api"

    return PlatformStats(
        platform="HackerEarth",
        username=username,
        profile_url=profile_url,
        metrics=metrics,
        status=status,
        source="public_api",
        source_type="live",
        retrieval_method=retrieval_method,
        retrieved_at=datetime.now(timezone.utc).isoformat(),
        error=error,
    )


def _fetch_hackerearth_api(username: str, metrics: Dict[str, Any], errors: List[str]) -> bool:
    """Fetch metrics and badges from HackerEarth's public community API."""
    headers = dict(HACKEREARTH_HEADERS)
    headers["Referer"] = f"https://www.hackerearth.com/@{username}/"

    # Metrics endpoint
    metrics_url = f"https://www.hackerearth.com/api/community/user/profile/{username}/metrics/"
    try:
        req = urllib.request.Request(metrics_url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode("utf-8"))
            if "points" in data:
                metrics["points"] = data["points"]
            if "problem_solved" in data:
                metrics["solved"] = data["problem_solved"]
            if "solutions_submitted" in data:
                metrics["submissions"] = data["solutions_submitted"]
            if "contest_rating" in data:
                metrics["contest_rating"] = data["contest_rating"]
    except Exception as e:
        errors.append(f"Metrics API error: {str(e)}")

    # Badges endpoint
    badges_url = f"https://www.hackerearth.com/api/community/user/profile/{username}/badges/"
    try:
        req = urllib.request.Request(badges_url, headers=headers)
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode("utf-8"))
            badges_list = []
            if isinstance(data, list):
                for category_item in data:
                    for b_entry in category_item.get("badges", []):
                        badge_obj = b_entry.get("badge", {})
                        b_name = badge_obj.get("name")
                        if b_name and b_name not in badges_list:
                            badges_list.append(b_name)
            if badges_list:
                metrics["badges"] = badges_list
                metrics["badges_count"] = len(badges_list)
    except Exception as e:
        errors.append(f"Badges API error: {str(e)}")

    return "points" in metrics or "solved" in metrics


def _fetch_hackerearth_browser(username: str, profile_url: str, metrics: Dict[str, Any]):
    """Use browser rendering to supplement track rankings, top percentiles, and star levels."""
    import asyncio
    from .browser_renderer import fetch_rendered_page

    async def _fetch():
        page_data = await fetch_rendered_page(
            profile_url,
            wait_timeout=20000,
            capture_network=False,
        )
        text = page_data.get("text", "")
        if not text:
            return

        # Top percentiles
        top_list = []
        for line in text.split("\n"):
            line = line.strip()
            m = re.match(r"^Top\s*(\d+%)\s*in\s*([A-Za-z\s]+)$", line)
            if m:
                top_list.append(f"Top {m.group(1)} in {m.group(2).strip()}")
        if top_list:
            metrics["top_percentiles"] = sorted(list(set(top_list)))

        # Basic Programming rank
        bp_match = re.search(r"Basic Programming\s*(\d+)\s*(\d+)", text)
        if bp_match:
            try:
                metrics["basic_programming_rank"] = int(bp_match.group(1))
                metrics["basic_programming_points"] = int(bp_match.group(2))
            except ValueError:
                pass

        # Algorithms rank
        algo_match = re.search(r"Algorithms\s*(\d+)\s*(\d+)", text)
        if algo_match:
            try:
                metrics["algorithms_rank"] = int(algo_match.group(1))
                metrics["algorithms_points"] = int(algo_match.group(2))
            except ValueError:
                pass

        # Submissions in last year
        subs_match = re.search(r"(\d+)\s*in the last year", text)
        if subs_match:
            try:
                metrics["submissions_last_year"] = int(subs_match.group(1))
            except ValueError:
                pass

    try:
        asyncio.run(_fetch())
    except Exception:
        pass
