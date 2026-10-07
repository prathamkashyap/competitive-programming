"""
CodeChef statistics provider using public profile page scraping.
"""

import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_codechef_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch CodeChef statistics from the public profile page.
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

        # Extract overall rating
        rating_match = re.search(r'"rating":\s*(\d+)', html)
        if rating_match:
            metrics["rating"] = int(rating_match.group(1))

        # Extract max rating
        max_rating_match = re.search(r'"maxRating":\s*(\d+)', html)
        if max_rating_match:
            metrics["max_rating"] = int(max_rating_match.group(1))

        # Extract stars
        stars_match = re.search(r'"stars":\s*"(\d+)"', html)
        if stars_match:
            metrics["stars"] = int(stars_match.group(1))

        # Extract solved count
        solved_match = re.search(r'"solved":\s*(\d+)', html)
        if solved_match:
            metrics["solved"] = int(solved_match.group(1))

        # Extract country rank
        country_rank_match = re.search(r'"countryRank":\s*(\d+)', html)
        if country_rank_match:
            metrics["country_rank"] = int(country_rank_match.group(1))

        # Extract global rank
        global_rank_match = re.search(r'"globalRank":\s*(\d+)', html)
        if global_rank_match:
            metrics["global_rank"] = int(global_rank_match.group(1))

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
