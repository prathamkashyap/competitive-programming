"""
CodeChef statistics provider using browser-rendered profile retrieval.
"""

import json
import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_codechef_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch CodeChef statistics using browser-rendered profile page.

    Attempts:
    1. Browser rendering if Playwright is available
    2. Simple scrape as fallback
    """
    # Try browser rendering first
    try:
        from .browser_renderer import is_playwright_available, fetch_rendered_page, extract_from_json

        if is_playwright_available():
            return fetch_codechef_with_browser(username, profile_url)
    except ImportError:
        pass
    except Exception as e:
        # Browser rendering failed, fall back to simple scrape
        pass

    # Fall back to simple scrape
    return fetch_codechef_simple(username, profile_url)


def fetch_codechef_with_browser(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch CodeChef statistics using browser rendering.
    """
    import asyncio
    from .browser_renderer import fetch_rendered_page, extract_from_json, extract_from_text

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
                            if "rating" in user_data:
                                metrics["rating"] = user_data["rating"]
                            if "maxRating" in user_data:
                                metrics["max_rating"] = user_data["maxRating"]
                            if "stars" in user_data:
                                metrics["stars"] = user_data["stars"]
                            if "solved" in user_data:
                                metrics["solved"] = user_data["solved"]
                            if "globalRank" in user_data:
                                metrics["global_rank"] = user_data["globalRank"]
                            if "countryRank" in user_data:
                                metrics["country_rank"] = user_data["countryRank"]
                        # Also check top-level keys
                        if "rating" in response_data:
                            metrics["rating"] = response_data["rating"]
                        if "solved" in response_data:
                            metrics["solved"] = response_data["solved"]
            except (json.JSONDecodeError, KeyError, TypeError):
                continue

        # Second, try to extract from embedded JSON
        if page_data.get("json_data"):
            json_paths = {
                "rating": [["user", "rating"]],
                "max_rating": [["user", "maxRating"]],
                "stars": [["user", "stars"]],
                "solved": [["user", "solved"]],
                "global_rank": [["user", "globalRank"]],
                "country_rank": [["user", "countryRank"]],
            }

            json_metrics = extract_from_json(page_data["json_data"], json_paths)
            metrics.update(json_metrics)

        # Extract from rendered text as fallback
        if not metrics or len(metrics) < 3:
            text_patterns = {
                "rating": r"(\d{3})\s*rating",  # Match 3-digit rating like 922
                "max_rating": r"highest rating[:\s]*(\d+)",
                "stars": r"(\d+)\s*stars?",
                "solved": r"(\d+)\s*solved",
                "global_rank": r"global rank[:\s]*(\d+)",
                "country_rank": r"country rank[:\s]*(\d+)",
            }

            text_metrics = extract_from_text(page_data["text"], text_patterns)
            metrics.update(text_metrics)

            # If still no rating, try without label
            if "rating" not in metrics:
                rating_match = re.search(r"(\d{3})\s*\*", page_data["text"])  # Match "922 *" pattern
                if rating_match:
                    metrics["rating"] = int(rating_match.group(1))

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="CodeChef",
            username=username,
            profile_url=profile_url,
            metrics=metrics,
            status=status,
            source="public_profile",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.utcnow().isoformat(),
            error=None if metrics else "Could not extract statistics from rendered profile",
        )

    try:
        return asyncio.run(_fetch())
    except Exception as e:
        return PlatformStats(
            platform="CodeChef",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Browser rendering error: {str(e)}",
            source="public_profile",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.utcnow().isoformat(),
        )


def fetch_codechef_simple(username: str, profile_url: str) -> PlatformStats:
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

        # Try to extract from embedded JSON
        json_match = re.search(r'window\.INITIAL_STATE\s*=\s*({.+?});', html, re.DOTALL)
        if json_match:
            try:
                json_data = json.loads(json_match.group(1))
                try:
                    user_data = json_data.get("user", {})
                    metrics["rating"] = user_data.get("rating")
                    metrics["max_rating"] = user_data.get("maxRating")
                    metrics["stars"] = user_data.get("stars")
                    metrics["solved"] = user_data.get("solved")
                    metrics["global_rank"] = user_data.get("globalRank")
                    metrics["country_rank"] = user_data.get("countryRank")
                except (KeyError, TypeError, AttributeError):
                    pass
            except (json.JSONDecodeError, ValueError):
                pass

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="CodeChef",
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
            platform="CodeChef",
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
            platform="CodeChef",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Unexpected error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
        )
