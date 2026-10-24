"""
Codeforces statistics provider using official API.
"""

import json
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus
from .utils import rate_limit_delay, retry_with_backoff


CODEFORCES_API_BASE = "https://codeforces.com/api/"
CODEFORCES_RATE_LIMIT_DELAY = 2.0  # Codeforces API rate limit: ~1 request per 2 seconds


@retry_with_backoff(max_retries=3, initial_delay=1.0, backoff_factor=2.0)
def _fetch_codeforces_api(url: str) -> Dict:
    """
    Fetch data from Codeforces API with retry logic.

    Args:
        url: API endpoint URL

    Returns:
        Parsed JSON response
    """
    with urllib.request.urlopen(url, timeout=10) as response:
        return json.loads(response.read().decode('utf-8'))


def fetch_codeforces_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch Codeforces statistics using the official public API.

    API endpoint: user.info, user.status
    Documentation: https://codeforces.com/apiHelp/methods?locale=en#user.info

    Rate limit: ~1 request per 2 seconds (enforced via delay between calls)
    """
    try:
        # Fetch user info
        url = f"{CODEFORCES_API_BASE}user.info?handles={username}"
        data = _fetch_codeforces_api(url)

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
                retrieved_at=datetime.now(timezone.utc).isoformat(),
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

        # Enforce rate limit delay before second API call
        rate_limit_delay(CODEFORCES_RATE_LIMIT_DELAY)

        # Fetch submission info for solved count
        try:
            submissions_url = f"{CODEFORCES_API_BASE}user.status?handle={username}"
            submissions_data = _fetch_codeforces_api(submissions_url)

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
            retrieved_at=datetime.now(timezone.utc).isoformat(),
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
            retrieved_at=datetime.now(timezone.utc).isoformat(),
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
            retrieved_at=datetime.now(timezone.utc).isoformat(),
        )
