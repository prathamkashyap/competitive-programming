"""
Codeforces statistics provider using official API.
"""

import json
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


CODEFORCES_API_BASE = "https://codeforces.com/api/"


def fetch_codeforces_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch Codeforces statistics using the official public API.

    API endpoint: user.info
    Documentation: https://codeforces.com/apiHelp/methods?locale=en#user.info
    """
    try:
        # Fetch user info
        url = f"{CODEFORCES_API_BASE}user.info?handles={username}"
        with urllib.request.urlopen(url, timeout=10) as response:
            data = json.loads(response.read().decode('utf-8'))

        if data.get("status") != "OK":
            error_msg = data.get("comment", "Unknown error")
            return PlatformStats(
                platform="Codeforces",
                username=username,
                profile_url=profile_url,
                status=RetrievalStatus.FAILED,
                error=f"API error: {error_msg}",
                source="official_api",
                retrieval_method="api",
                retrieved_at=datetime.utcnow().isoformat(),
            )

        user_info = data["result"][0]

        # Extract metrics
        metrics = {
            "rating": user_info.get("rating"),
            "max_rating": user_info.get("maxRating"),
            "rank": user_info.get("rank"),
            "max_rank": user_info.get("maxRank"),
            "title_photo": user_info.get("titlePhoto"),
        }

        # Fetch submission info for solved count
        try:
            submissions_url = f"{CODEFORCES_API_BASE}user.status?handle={username}"
            with urllib.request.urlopen(submissions_url, timeout=10) as response:
                submissions_data = json.loads(response.read().decode('utf-8'))

            if submissions_data.get("status") == "OK":
                submissions = submissions_data["result"]
                # Count unique accepted problems
                accepted_problems = set()
                for sub in submissions:
                    if sub.get("verdict") == "OK":
                        problem_id = f"{sub['problem']['contestId']}_{sub['problem']['index']}"
                        accepted_problems.add(problem_id)
                metrics["solved"] = len(accepted_problems)
        except Exception as e:
            # Submission fetch is optional
            metrics["solved"] = None

        return PlatformStats(
            platform="Codeforces",
            username=username,
            profile_url=profile_url,
            metrics=metrics,
            status=RetrievalStatus.SUCCESS,
            source="official_api",
            retrieval_method="api",
            retrieved_at=datetime.utcnow().isoformat(),
        )

    except urllib.error.URLError as e:
        return PlatformStats(
            platform="Codeforces",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Network error: {str(e)}",
            source="official_api",
            retrieval_method="api",
            retrieved_at=datetime.utcnow().isoformat(),
        )
    except Exception as e:
        return PlatformStats(
            platform="Codeforces",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Unexpected error: {str(e)}",
            source="official_api",
            retrieval_method="api",
            retrieved_at=datetime.utcnow().isoformat(),
        )
