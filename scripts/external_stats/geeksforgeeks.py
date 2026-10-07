"""
GeeksforGeeks statistics provider using browser-rendered profile retrieval.
"""

import json
import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_geeksforgeeks_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch GeeksforGeeks statistics using browser-rendered profile page.

    Attempts:
    1. Browser rendering if Playwright is available
    2. Simple scrape as fallback
    """
    # Try browser rendering first
    try:
        from .browser_renderer import is_playwright_available, fetch_rendered_page, extract_from_text

        if is_playwright_available():
            return fetch_geeksforgeeks_with_browser(username, profile_url)
    except ImportError:
        pass
    except Exception as e:
        # Browser rendering failed, fall back to simple scrape
        pass

    # Fall back to simple scrape
    return fetch_geeksforgeeks_simple(username, profile_url)


def fetch_geeksforgeeks_with_browser(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch GeeksforGeeks statistics using browser rendering with network inspection.
    """
    import asyncio
    from .browser_renderer import fetch_rendered_page, extract_from_text

    async def _fetch():
        page_data = await fetch_rendered_page(
            profile_url,
            wait_selector=None,
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
                            if "coding_score" in user_data:
                                metrics["coding_score"] = user_data["coding_score"]
                            if "solved" in user_data:
                                metrics["solved"] = user_data["solved"]
                            if "streak" in user_data:
                                metrics["streak"] = user_data["streak"]
                        # Also check top-level keys
                        if "coding_score" in response_data:
                            metrics["coding_score"] = response_data["coding_score"]
                        if "solved" in response_data:
                            metrics["solved"] = response_data["solved"]
                        if "streak" in response_data:
                            metrics["streak"] = response_data["streak"]
            except (json.JSONDecodeError, KeyError, TypeError):
                continue

        # Second, extract from rendered text
        if not metrics or len(metrics) < 2:
            text_patterns = {
                "coding_score": r"(\d+)\s*coding\s*score",
                "overall_score": r"(\d+)\s*overall\s*score",
                "solved": r"(\d+)\s*problems?\s*solved",
                "streak": r"(\d+)\s*day\s*streak",
            }

            text_metrics = extract_from_text(page_data["text"], text_patterns)
            metrics.update(text_metrics)

            # Try more generic patterns if specific ones fail
            if not metrics:
                generic_patterns = {
                    "coding_score": r"(\d+)\s*(?:coding|practice)\s*score",
                    "solved": r"(\d+)\s*(?:problems?|questions)\s*solved",
                    "streak": r"(\d+)\s*(?:day|streak)",
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
            platform="GeeksforGeeks",
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
            platform="GeeksforGeeks",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Browser rendering error: {str(e)}",
            source="public_profile",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.utcnow().isoformat(),
        )


def fetch_geeksforgeeks_simple(username: str, profile_url: str) -> PlatformStats:
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
        score_match = re.search(r'(\d+)\s*coding\s*score', html, re.IGNORECASE)
        if score_match:
            metrics["coding_score"] = int(score_match.group(1))

        solved_match = re.search(r'(\d+)\s*problems?\s*solved', html, re.IGNORECASE)
        if solved_match:
            metrics["solved"] = int(solved_match.group(1))

        streak_match = re.search(r'(\d+)\s*day\s*streak', html, re.IGNORECASE)
        if streak_match:
            metrics["streak"] = int(streak_match.group(1))

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="GeeksforGeeks",
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
            platform="GeeksforGeeks",
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
            platform="GeeksforGeeks",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Unexpected error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
        )
