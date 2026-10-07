"""
GeeksforGeeks statistics provider using public profile page scraping.
"""

import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_geeksforgeeks_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch GeeksforGeeks statistics from the public profile page.
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

        # Extract coding score
        score_match = re.search(r'(\d+)\s*coding\s*score', html, re.IGNORECASE)
        if score_match:
            metrics["coding_score"] = int(score_match.group(1))

        # Extract overall score
        overall_score_match = re.search(r'(\d+)\s*overall\s*score', html, re.IGNORECASE)
        if overall_score_match:
            metrics["overall_score"] = int(overall_score_match.group(1))

        # Extract problem solved count
        solved_match = re.search(r'(\d+)\s*problems?\s*solved', html, re.IGNORECASE)
        if solved_match:
            metrics["solved"] = int(solved_match.group(1))

        # Extract streak
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
