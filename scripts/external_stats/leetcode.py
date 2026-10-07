"""
LeetCode statistics provider using public GraphQL API with browser fallback.
"""

import json
import urllib.request
import urllib.error
from typing import Dict, Any, Optional, List
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"

GRAPHQL_HEADERS = {
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Referer": "https://leetcode.com/",
    "Origin": "https://leetcode.com",
}


def fetch_leetcode_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch LeetCode statistics using public GraphQL queries, with browser fallback.
    """
    # Try GraphQL first
    stats = _fetch_leetcode_graphql(username, profile_url)
    if stats.status in [RetrievalStatus.SUCCESS, RetrievalStatus.PARTIAL]:
        return stats

    # Try browser rendering fallback if Playwright is available
    try:
        from .browser_renderer import is_playwright_available
        if is_playwright_available():
            browser_stats = _fetch_leetcode_browser(username, profile_url)
            if browser_stats.status in [RetrievalStatus.SUCCESS, RetrievalStatus.PARTIAL]:
                return browser_stats
    except Exception:
        pass

    return stats


def _execute_graphql(query: str, variables: Dict[str, Any], timeout: int = 15) -> Optional[Dict]:
    """Execute a single GraphQL query against LeetCode's endpoint."""
    try:
        payload = {"query": query, "variables": variables}
        data = json.dumps(payload).encode("utf-8")
        headers = dict(GRAPHQL_HEADERS)
        if "username" in variables:
            headers["Referer"] = f"https://leetcode.com/u/{variables['username']}/"

        req = urllib.request.Request(LEETCODE_GRAPHQL_URL, data=data, headers=headers, method="POST")
        with urllib.request.urlopen(req, timeout=timeout) as response:
            return json.loads(response.read().decode("utf-8"))
    except Exception:
        return None


def _fetch_leetcode_graphql(username: str, profile_url: str) -> PlatformStats:
    """Query LeetCode's public GraphQL API across multiple focused query families."""
    metrics: Dict[str, Any] = {}

    # 1. Profile & Submission Statistics
    profile_query = """
    query userPublicProfile($username: String!) {
        matchedUser(username: $username) {
            username
            profile {
                ranking
                reputation
                solutionCount
            }
            submitStats {
                acSubmissionNum {
                    difficulty
                    count
                    submissions
                }
                totalSubmissionNum {
                    difficulty
                    count
                    submissions
                }
            }
        }
    }
    """
    res = _execute_graphql(profile_query, {"username": username})
    if res and "data" in res and res["data"].get("matchedUser"):
        user = res["data"]["matchedUser"]
        profile = user.get("profile") or {}
        if profile.get("ranking"):
            metrics["global_rank"] = profile["ranking"]
        if profile.get("reputation") is not None:
            metrics["reputation"] = profile["reputation"]
        if profile.get("solutionCount") is not None:
            metrics["solution_count"] = profile["solutionCount"]

        submit_stats = user.get("submitStats") or {}
        ac_list = submit_stats.get("acSubmissionNum") or []
        for item in ac_list:
            diff = (item.get("difficulty") or "").lower()
            cnt = item.get("count")
            subs = item.get("submissions")
            if diff == "all":
                metrics["solved"] = cnt
                metrics["ac_submissions"] = subs
            elif diff in ["easy", "medium", "hard"] and cnt is not None:
                metrics[diff] = cnt

        total_list = submit_stats.get("totalSubmissionNum") or []
        for item in total_list:
            diff = (item.get("difficulty") or "").lower()
            if diff == "all":
                total_subs = item.get("submissions")
                if total_subs is not None:
                    metrics["submissions"] = total_subs

        # Compute acceptance rate if both ac_submissions and submissions exist
        if "ac_submissions" in metrics and "submissions" in metrics and metrics["submissions"] > 0:
            rate = (metrics["ac_submissions"] / metrics["submissions"]) * 100
            metrics["acceptance_rate"] = round(rate, 1)

    # 2. Badges
    badges_query = """
    query userBadges($username: String!) {
        matchedUser(username: $username) {
            badges {
                id
                name
                displayName
                icon
                creationDate
            }
            activeBadge {
                displayName
            }
        }
    }
    """
    res = _execute_graphql(badges_query, {"username": username})
    if res and "data" in res and res["data"].get("matchedUser"):
        badge_data = res["data"]["matchedUser"]
        badge_list = badge_data.get("badges") or []
        metrics["badges_count"] = len(badge_list)
        badge_names = [b.get("displayName") or b.get("name") for b in badge_list if b.get("displayName") or b.get("name")]
        if badge_names:
            metrics["badges"] = badge_names
        active = badge_data.get("activeBadge")
        if active and active.get("displayName"):
            metrics["active_badge"] = active["displayName"]

    # 3. Calendar & Streaks
    calendar_query = """
    query userCalendar($username: String!) {
        matchedUser(username: $username) {
            userCalendar {
                activeYears
                streak
                totalActiveDays
            }
        }
    }
    """
    res = _execute_graphql(calendar_query, {"username": username})
    if res and "data" in res and res["data"].get("matchedUser"):
        cal = res["data"]["matchedUser"].get("userCalendar") or {}
        if cal.get("streak") is not None:
            metrics["streak_days"] = cal["streak"]
        if cal.get("totalActiveDays") is not None:
            metrics["total_active_days"] = cal["totalActiveDays"]
        if cal.get("activeYears"):
            metrics["active_years"] = cal["activeYears"]

    # 4. Language Breakdown
    language_query = """
    query languageStats($username: String!) {
        matchedUser(username: $username) {
            languageProblemCount {
                languageName
                problemsSolved
            }
        }
    }
    """
    res = _execute_graphql(language_query, {"username": username})
    if res and "data" in res and res["data"].get("matchedUser"):
        lang_list = res["data"]["matchedUser"].get("languageProblemCount") or []
        langs = {item["languageName"]: item["problemsSolved"] for item in lang_list if item.get("languageName") and item.get("problemsSolved") is not None}
        if langs:
            metrics["languages"] = langs

    # 5. Contest Ranking
    contest_query = """
    query userContestRanking($username: String!) {
        userContestRanking(username: $username) {
            attendedContestsCount
            rating
            globalRanking
            totalParticipants
            topPercentage
            badge {
                name
            }
        }
    }
    """
    res = _execute_graphql(contest_query, {"username": username})
    if res and "data" in res and res["data"].get("userContestRanking"):
        contest = res["data"]["userContestRanking"]
        if contest.get("rating"):
            metrics["contest_rating"] = round(contest["rating"], 1)
        if contest.get("globalRanking"):
            metrics["contest_global_rank"] = contest["globalRanking"]
        if contest.get("attendedContestsCount") is not None:
            metrics["contests_attended"] = contest["attendedContestsCount"]
        if contest.get("topPercentage") is not None:
            metrics["contest_top_percentage"] = contest["topPercentage"]

    # 6. Recent Accepted Submissions
    recent_query = """
    query recentAcSubmissions($username: String!) {
        recentAcSubmissionList(username: $username, limit: 5) {
            title
            titleSlug
            timestamp
        }
    }
    """
    res = _execute_graphql(recent_query, {"username": username})
    if res and "data" in res and res["data"].get("recentAcSubmissionList"):
        recents = res["data"]["recentAcSubmissionList"]
        if recents:
            metrics["recent_ac"] = [r.get("title") for r in recents if r.get("title")]

    # Determine status
    if "solved" in metrics and "easy" in metrics and "medium" in metrics and "hard" in metrics:
        status = RetrievalStatus.SUCCESS
        error = None
    elif metrics:
        status = RetrievalStatus.PARTIAL
        error = "Retrieved partial LeetCode statistics"
    else:
        status = RetrievalStatus.UNAVAILABLE
        error = "Could not retrieve statistics from LeetCode GraphQL API"

    return PlatformStats(
        platform="LeetCode",
        username=username,
        profile_url=profile_url,
        metrics=metrics,
        status=status,
        source="public_graphql",
        source_type="live",
        retrieval_method="graphql_api",
        retrieved_at=datetime.now(timezone.utc).isoformat(),
        error=error,
    )


def _fetch_leetcode_browser(username: str, profile_url: str) -> PlatformStats:
    """Fallback using Playwright browser rendering to extract Next.js embedded data."""
    import asyncio
    from .browser_renderer import fetch_rendered_page

    async def _fetch():
        page_data = await fetch_rendered_page(
            profile_url,
            wait_timeout=25000,
            capture_network=True,
        )
        metrics: Dict[str, Any] = {}

        # Look in captured network requests for GraphQL responses
        for req in page_data.get("network_requests", []):
            if "graphql" in req.get("url", "") and "response_body" in req:
                try:
                    data = json.loads(req["response_body"])
                    user = data.get("data", {}).get("matchedUser", {})
                    stats = user.get("submitStats", {}).get("acSubmissionNum", [])
                    for s in stats:
                        d = s.get("difficulty", "").lower()
                        if d == "all":
                            metrics["solved"] = s.get("count")
                        elif d in ["easy", "medium", "hard"]:
                            metrics[d] = s.get("count")
                except Exception:
                    continue

        if "solved" in metrics:
            status = RetrievalStatus.SUCCESS
            error = None
        elif metrics:
            status = RetrievalStatus.PARTIAL
            error = "Partial data from browser network capture"
        else:
            status = RetrievalStatus.UNAVAILABLE
            error = "Could not extract LeetCode data via browser"

        return PlatformStats(
            platform="LeetCode",
            username=username,
            profile_url=profile_url,
            metrics=metrics,
            status=status,
            source="public_profile",
            source_type="live",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.now(timezone.utc).isoformat(),
            error=error,
        )

    try:
        return asyncio.run(_fetch())
    except Exception as e:
        return PlatformStats(
            platform="LeetCode",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Browser error: {str(e)}",
            source="public_profile",
            source_type="live",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.now(timezone.utc).isoformat(),
        )
