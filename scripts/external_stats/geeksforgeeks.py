"""
GeeksforGeeks statistics provider using embedded page state, public practice API, and browser fallback.
"""

import json
import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional, List
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


GFG_HEADERS = {
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Referer": "https://www.geeksforgeeks.org/",
    "Origin": "https://www.geeksforgeeks.org",
}


def fetch_geeksforgeeks_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch GeeksforGeeks statistics using public endpoints and embedded Next.js state.
    """
    metrics: Dict[str, Any] = {}
    errors: List[str] = []

    # 1. Fetch practice submissions & difficulty breakdown from practiceapi
    _fetch_gfg_practice_api(username, metrics, errors)

    # 2. Fetch user profile page HTML to extract embedded state (coding score, streaks, POTD)
    _fetch_gfg_embedded_state(username, metrics, errors)

    # 3. If primary metrics missing, use browser rendering fallback
    if "coding_score" not in metrics or "solved" not in metrics:
        try:
            from .browser_renderer import is_playwright_available
            if is_playwright_available():
                _fetch_gfg_browser(username, profile_url, metrics)
        except Exception as e:
            errors.append(f"Browser fallback error: {str(e)}")

    # Determine status
    if "coding_score" in metrics and "solved" in metrics:
        status = RetrievalStatus.SUCCESS
        error = None
    elif metrics:
        status = RetrievalStatus.PARTIAL
        error = "; ".join(errors) if errors else "Retrieved partial GeeksforGeeks statistics"
    else:
        status = RetrievalStatus.UNAVAILABLE
        error = "; ".join(errors) if errors else "Could not retrieve statistics from GeeksforGeeks"

    return PlatformStats(
        platform="GeeksforGeeks",
        username=username,
        profile_url=profile_url,
        metrics=metrics,
        status=status,
        source="public_profile",
        source_type="live",
        retrieval_method="embedded_state_and_api",
        retrieved_at=datetime.now(timezone.utc).isoformat(),
        error=error,
    )


def _fetch_gfg_practice_api(username: str, metrics: Dict[str, Any], errors: List[str]):
    """Fetch problem submissions breakdown and yearwise activity from practiceapi."""
    api_url = "https://practiceapi.geeksforgeeks.org/api/v1/user/problems/submissions/"
    headers = dict(GFG_HEADERS)
    headers["Content-Type"] = "application/json"
    headers["Referer"] = f"https://www.geeksforgeeks.org/profile/{username}?tab=activity"

    # A. Difficulty breakdown
    try:
        payload = {"handle": username, "requestType": "", "year": "", "month": ""}
        req = urllib.request.Request(api_url, data=json.dumps(payload).encode("utf-8"), headers=headers, method="POST")
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode("utf-8"))
            if data.get("status") == "success" and "result" in data:
                result = data["result"]
                difficulty_counts = {}
                total_solved = 0
                for diff, problems in result.items():
                    diff_name = diff.lower()
                    cnt = len(problems) if isinstance(problems, dict) else len(problems)
                    difficulty_counts[diff_name] = cnt
                    total_solved += cnt

                for diff, count in difficulty_counts.items():
                    metrics[f"{diff}_solved"] = count
                metrics["solved"] = total_solved
    except Exception as e:
        errors.append(f"Practice API submissions error: {str(e)}")

    # B. Yearwise submissions (for current year 2026)
    try:
        current_year = str(datetime.now().year)
        payload = {"handle": username, "requestType": "getYearwiseUserSubmissions", "year": current_year, "month": ""}
        req = urllib.request.Request(api_url, data=json.dumps(payload).encode("utf-8"), headers=headers, method="POST")
        with urllib.request.urlopen(req, timeout=10) as resp:
            data = json.loads(resp.read().decode("utf-8"))
            if data.get("status") == "success" and "result" in data:
                year_map = data["result"]
                if isinstance(year_map, dict):
                    metrics[f"submissions_{current_year}"] = sum(year_map.values())
                    metrics[f"active_days_{current_year}"] = len(year_map)
    except Exception as e:
        errors.append(f"Practice API yearwise error: {str(e)}")


def _fetch_gfg_embedded_state(username: str, metrics: Dict[str, Any], errors: List[str]):
    """Fetch user profile HTML and parse embedded mentor/user stats object."""
    urls = [
        f"https://www.geeksforgeeks.org/user/{username}/",
        f"https://www.geeksforgeeks.org/profile/{username}?tab=activity",
    ]

    for url in urls:
        try:
            req = urllib.request.Request(url, headers=GFG_HEADERS)
            with urllib.request.urlopen(req, timeout=10) as resp:
                html = resp.read().decode("utf-8", errors="ignore")

            # Look for score and POTD streak in HTML embedded state
            score_m = re.search(r'\\"score\\":\s*(\d+)', html)
            if score_m:
                metrics["coding_score"] = int(score_m.group(1))

            longest_streak_m = re.search(r'\\"pod_solved_longest_streak\\":\s*(\d+)', html)
            if longest_streak_m:
                metrics["longest_streak_days"] = int(longest_streak_m.group(1))

            current_streak_m = re.search(r'\\"pod_solved_current_streak\\":\s*(\d+)', html)
            if current_streak_m:
                metrics["current_streak_days"] = int(current_streak_m.group(1))

            potd_solved_m = re.search(r'\\"pod_correct_submissions_count\\":\s*(\d+)', html)
            if potd_solved_m:
                metrics["potd_solved"] = int(potd_solved_m.group(1))

            monthly_score_m = re.search(r'\\"monthly_score\\":\s*(\d+)', html)
            if monthly_score_m:
                metrics["monthly_score"] = int(monthly_score_m.group(1))

            total_problems_m = re.search(r'\\"total_problems_solved\\":\s*(\d+)', html)
            if total_problems_m and "solved" not in metrics:
                metrics["solved"] = int(total_problems_m.group(1))

            if "coding_score" in metrics:
                break
        except Exception as e:
            errors.append(f"Embedded state error ({url}): {str(e)}")


def _fetch_gfg_browser(username: str, profile_url: str, metrics: Dict[str, Any]):
    """Browser rendering fallback via Playwright."""
    import asyncio
    from .browser_renderer import fetch_rendered_page

    async def _fetch():
        activity_url = f"https://www.geeksforgeeks.org/profile/{username}?tab=activity"
        page_data = await fetch_rendered_page(activity_url, wait_timeout=20000, capture_network=False)
        text = page_data.get("text", "")
        if not text:
            return

        score_m = re.search(r"Coding Score\s*(\d+)", text)
        if score_m:
            metrics["coding_score"] = int(score_m.group(1))

        solved_m = re.search(r"Problems Solved\s*(\d+)", text)
        if solved_m and "solved" not in metrics:
            metrics["solved"] = int(solved_m.group(1))

        streak_m = re.search(r"Longest Streak:\s*(\d+)\s*Days", text)
        if streak_m:
            metrics["longest_streak_days"] = int(streak_m.group(1))

        potd_m = re.search(r"POTDs Solved:\s*(\d+)", text)
        if potd_m:
            metrics["potd_solved"] = int(potd_m.group(1))

    try:
        asyncio.run(_fetch())
    except Exception:
        pass
