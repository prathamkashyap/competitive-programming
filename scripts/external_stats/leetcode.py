"""
LeetCode statistics provider using browser-rendered profile retrieval.
"""

import json
import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_leetcode_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch LeetCode statistics using browser-rendered profile page.

    Attempts:
    1. Simple scrape (for backward compatibility)
    2. Browser rendering if Playwright is available
    """
    # First try browser rendering if available
    try:
        from .browser_renderer import is_playwright_available, fetch_rendered_page, extract_from_json

        if is_playwright_available():
            return fetch_leetcode_with_browser(username, profile_url)
    except ImportError:
        pass
    except Exception as e:
        # Browser rendering failed, fall back to simple scrape
        pass

    # Fall back to simple scrape
    return fetch_leetcode_simple(username, profile_url)


def fetch_leetcode_with_browser(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch LeetCode statistics using browser rendering with network inspection.
    """
    import asyncio
    from .browser_renderer import fetch_rendered_page, extract_from_json

    async def _fetch():
        # Fetch rendered page with network capture
        page_data = await fetch_rendered_page(
            profile_url,
            wait_selector=None,
            wait_timeout=60000,
            capture_network=True,
        )

        metrics = {}

        # First try to extract from embedded JSON (Next.js data)
        if page_data["json_data"]:
            # LeetCode stores data in __NEXT_DATA__
            # Try multiple possible paths for user data
            json_paths = {
                "solved": [["props", "pageProps", "data", "user", "acSubmissionNum", 0, "count"],
                          ["props", "pageProps", "data", "matchedUser", "submitStats", "acSubmissionNum", 0, "count"]],
                "easy": [["props", "pageProps", "data", "user", "acSubmissionNum", 1, "count"],
                        ["props", "pageProps", "data", "matchedUser", "submitStats", "acSubmissionNum", 1, "count"]],
                "medium": [["props", "pageProps", "data", "user", "acSubmissionNum", 2, "count"],
                          ["props", "pageProps", "data", "matchedUser", "submitStats", "acSubmissionNum", 2, "count"]],
                "hard": [["props", "pageProps", "data", "user", "acSubmissionNum", 3, "count"],
                        ["props", "pageProps", "data", "matchedUser", "submitStats", "acSubmissionNum", 3, "count"]],
                "contest_rating": [["props", "pageProps", "data", "user", "userContestRanking", "rating"],
                                 ["props", "pageProps", "data", "matchedUser", "userContestRanking", "rating"]],
                "global_rank": [["props", "pageProps", "data", "user", "userContestRanking", "globalRanking"],
                               ["props", "pageProps", "data", "matchedUser", "userContestRanking", "globalRanking"]],
                "badges": [["props", "pageProps", "data", "matchedUser", "badges", "length"]],
            }

            json_metrics = extract_from_json(page_data["json_data"], json_paths)
            metrics.update(json_metrics)

        # Second, try to extract from network requests (GraphQL/JSON)
        if not metrics or len(metrics) < 3:
            for request in page_data.get("network_requests", []):
                try:
                    if "response_body" in request:
                        response_data = json.loads(request["response_body"])
                        # Try to extract from GraphQL responses
                        if "data" in response_data:
                            data = response_data["data"]
                            # Try to find user data
                            if "user" in data:
                                user_data = data["user"]
                                if "acSubmissionNum" in user_data:
                                    sub_nums = user_data["acSubmissionNum"]
                                    if isinstance(sub_nums, list) and len(sub_nums) >= 4:
                                        metrics["solved"] = sub_nums[0].get("count")
                                        metrics["easy"] = sub_nums[1].get("count")
                                        metrics["medium"] = sub_nums[2].get("count")
                                        metrics["hard"] = sub_nums[3].get("count")
                            if "matchedUser" in data:
                                matched_user = data["matchedUser"]
                                if "submitStats" in matched_user:
                                    sub_stats = matched_user["submitStats"]
                                    if "acSubmissionNum" in sub_stats:
                                        sub_nums = sub_stats["acSubmissionNum"]
                                        if isinstance(sub_nums, list) and len(sub_nums) >= 4:
                                            if "solved" not in metrics:
                                                metrics["solved"] = sub_nums[0].get("count")
                                            if "easy" not in metrics:
                                                metrics["easy"] = sub_nums[1].get("count")
                                            if "medium" not in metrics:
                                                metrics["medium"] = sub_nums[2].get("count")
                                            if "hard" not in metrics:
                                                metrics["hard"] = sub_nums[3].get("count")
                                if "userContestRanking" in matched_user:
                                    contest = matched_user["userContestRanking"]
                                    if "rating" in contest and "contest_rating" not in metrics:
                                        metrics["contest_rating"] = contest["rating"]
                                    if "globalRanking" in contest and "global_rank" not in metrics:
                                        metrics["global_rank"] = contest["globalRanking"]
                except (json.JSONDecodeError, KeyError, TypeError):
                    continue

        # Third, extract from rendered text as last resort
        if not metrics or len(metrics) < 2:
            text_patterns = {
                "solved": r"Solved\s*(\d+)",
                "easy": r"Easy\s*(\d+)",
                "medium": r"Medium\s*(\d+)",
                "hard": r"Hard\s*(\d+)",
                "rating": r"Rating\s*(\d+)",
                "global_rank": r"Rank[:\s]*(\d+)",
            }

            from .browser_renderer import extract_from_text
            text_metrics = extract_from_text(page_data["text"], text_patterns)
            metrics.update(text_metrics)

            # Debug: try more generic patterns
            if not metrics:
                generic_patterns = {
                    "solved": r"(\d+)\s*(?:solved|accepted|submissions)",
                    "rating": r"(\d+)\s*(?:rating|rank)",
                }
                generic_metrics = extract_from_text(page_data["text"], generic_patterns)
                metrics.update(generic_metrics)

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS if len(metrics) >= 3 else RetrievalStatus.PARTIAL
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="LeetCode",
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
            platform="LeetCode",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Browser rendering error: {str(e)}",
            source="public_profile",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.utcnow().isoformat(),
        )


def fetch_leetcode_simple(username: str, profile_url: str) -> PlatformStats:
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

        # Try to extract from embedded JSON in HTML
        json_match = re.search(r'__NEXT_DATA__\s*=\s*({.+?});</script>', html, re.DOTALL)
        if json_match:
            try:
                json_data = json.loads(json_match.group(1))
                # Extract from JSON structure
                try:
                    user_data = json_data.get("props", {}).get("pageProps", {}).get("data", {}).get("user", {})
                    submission_num = user_data.get("acSubmissionNum", [])
                    if submission_num and len(submission_num) >= 4:
                        metrics["solved"] = submission_num[0].get("count")
                        metrics["easy"] = submission_num[1].get("count")
                        metrics["medium"] = submission_num[2].get("count")
                        metrics["hard"] = submission_num[3].get("count")

                    contest_ranking = user_data.get("userContestRanking", {})
                    if contest_ranking:
                        metrics["contest_rating"] = contest_ranking.get("rating")
                        metrics["global_rank"] = contest_ranking.get("globalRanking")

                    badges = user_data.get("badges")
                    if badges:
                        metrics["badges"] = len(badges)
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
            platform="LeetCode",
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
            platform="LeetCode",
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
            platform="LeetCode",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Unexpected error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
        )
