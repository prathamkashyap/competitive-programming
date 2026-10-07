"""
LeetCode statistics provider using public profile page scraping.
"""

import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_leetcode_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch LeetCode statistics from the public profile page.

    LeetCode does not have a reliable official public API.
    We scrape the public profile page instead.
    """
    try:
        # Use proper user agent to avoid 403
        headers = {
            'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
        }
        req = urllib.request.Request(profile_url, headers=headers)

        # Fetch the profile page
        with urllib.request.urlopen(req, timeout=10) as response:
            html = response.read().decode('utf-8')

        metrics = {}

        # Extract total solved count
        # Pattern: "Solved": "455" or similar
        solved_match = re.search(r'"solved":\s*(\d+)', html)
        if solved_match:
            metrics["solved"] = int(solved_match.group(1))

        # Extract difficulty breakdown
        # Pattern: "easy": "160", "medium": "232", "hard": "63"
        easy_match = re.search(r'"easy":\s*(\d+)', html)
        medium_match = re.search(r'"medium":\s*(\d+)', html)
        hard_match = re.search(r'"hard":\s*(\d+)', html)

        if easy_match:
            metrics["easy"] = int(easy_match.group(1))
        if medium_match:
            metrics["medium"] = int(medium_match.group(1))
        if hard_match:
            metrics["hard"] = int(hard_match.group(1))

        # Extract contest rating
        rating_match = re.search(r'"rating":\s*(\d+)', html)
        if rating_match:
            metrics["contest_rating"] = int(rating_match.group(1))

        # Extract global ranking
        rank_match = re.search(r'"globalRanking":\s*(\d+)', html)
        if rank_match:
            metrics["global_rank"] = int(rank_match.group(1))

        # Extract badge count
        badge_match = re.search(r'"badges":\s*(\d+)', html)
        if badge_match:
            metrics["badges"] = int(badge_match.group(1))

        # Determine status based on what we found
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
