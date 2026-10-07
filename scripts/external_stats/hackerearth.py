"""
HackerEarth statistics provider using browser-rendered profile retrieval.
"""

import json
import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_hackerearth_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch HackerEarth statistics using browser-rendered profile page.

    Attempts:
    1. Browser rendering if Playwright is available
    2. Simple scrape as fallback
    """
    # Try browser rendering first
    try:
        from .browser_renderer import is_playwright_available, fetch_rendered_page, extract_from_text

        if is_playwright_available():
            return fetch_hackerearth_with_browser(username, profile_url)
    except ImportError:
        pass
    except Exception as e:
        # Browser rendering failed, fall back to simple scrape
        pass

    # Fall back to simple scrape
    return fetch_hackerearth_simple(username, profile_url)


def fetch_hackerearth_with_browser(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch HackerEarth statistics using browser rendering with network inspection.
    """
    import asyncio
    from .browser_renderer import fetch_rendered_page, extract_from_text

    async def _fetch():
        page_data = await fetch_rendered_page(
            profile_url,
            wait_selector=None,  # Don't wait for specific selector
            wait_timeout=30000,
            capture_network=True,
        )

        metrics = {}

        # First, try to extract from network requests (JSON/GraphQL)
        for request in page_data.get("network_requests", []):
            try:
                if "response_body" in request:
                    response_data = json.loads(request["response_body"])
                    # Try to find user/profile data
                    if isinstance(response_data, dict):
                        # Look for common profile data keys
                        if "user" in response_data:
                            user_data = response_data["user"]
                            if "points" in user_data:
                                metrics["points"] = user_data["points"]
                            if "solved" in user_data:
                                metrics["solved"] = user_data["solved"]
                            if "submissions" in user_data:
                                metrics["submissions"] = user_data["submissions"]
                        # Also check top-level keys
                        if "points" in response_data:
                            metrics["points"] = response_data["points"]
                        if "solved" in response_data:
                            metrics["solved"] = response_data["solved"]
                        if "submissions" in response_data:
                            metrics["submissions"] = response_data["submissions"]
            except (json.JSONDecodeError, KeyError, TypeError):
                continue

        # Second, extract from rendered text with improved patterns based on screenshot
        if not metrics or len(metrics) < 2:
            text_patterns = {
                "points": r"(\d{4})\s*points",  # Match 4-digit points like 4300
                "solved": r"problems?\s*solved[:\s]*(\d+)",
                "submissions": r"submissions[:\s]*(\d+)",
                "rank": r"rank[:\s]*(\d+)",
                "streak": r"(\d+)\s*day\s*streak",
                "top_1_percent": r"Top\s*1%",
                "top_10_percent": r"Top\s*10%",
                "top_22_percent": r"Top\s*22%",
            }

            text_metrics = extract_from_text(page_data["text"], text_patterns)
            metrics.update(text_metrics)

            # Try more generic patterns if specific ones fail
            if not metrics or "points" not in metrics:
                generic_patterns = {
                    "points": r"(\d{4,})\s*(?:points|score)",  # Match 4+ digit numbers (like 4300)
                    "solved": r"(\d+)\s*(?:solved|problems)",
                    "submissions": r"(\d+)\s*(?:submissions|attempts)",
                }
                generic_metrics = extract_from_text(page_data["text"], generic_patterns)
                metrics.update(generic_metrics)

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS if len(metrics) >= 2 else RetrievalStatus.PARTIAL
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="HackerEarth",
            username=username,
            profile_url=profile_url,
            metrics=metrics,
            status=status,
            source="public_profile",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.utcnow().isoformat(),
            error=None if metrics else "Could not extract statistics from rendered profile or network requests",
        )

    try:
        return asyncio.run(_fetch())
    except Exception as e:
        return PlatformStats(
            platform="HackerEarth",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Browser rendering error: {str(e)}",
            source="public_profile",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.utcnow().isoformat(),
        )


def fetch_hackerearth_simple(username: str, profile_url: str) -> PlatformStats:
    """
    Fallback: simple HTTP scrape without browser rendering.
    """
    try:
        headers = {
            'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
        }
        req = urllib.request.Request(profile_url, headers=headers)

        with urllib.request.urlopen(req, timeout=10) as response:
            html = response.read().decode('utf-8')

        metrics = {}

        # Extract from HTML
        points_match = re.search(r'(\d+)\s*points', html, re.IGNORECASE)
        if points_match:
            metrics["points"] = int(points_match.group(1))

        solved_match = re.search(r'(\d+)\s*solved', html, re.IGNORECASE)
        if solved_match:
            metrics["solved"] = int(solved_match.group(1))

        submissions_match = re.search(r'(\d+)\s*submissions', html, re.IGNORECASE)
        if submissions_match:
            metrics["submissions"] = int(submissions_match.group(1))

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="HackerEarth",
            username=username,
            profile_url=profile_url,
            metrics=metrics,
            status=status,
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
            error=None if metrics else "Could not extract statistics from profile page",
        )

    except urllib.error.URLError as e:
        return PlatformStats(
            platform="HackerEarth",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Network error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
        )
    except Exception as e:
        return PlatformStats(
            platform="HackerEarth",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Unexpected error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
        )
