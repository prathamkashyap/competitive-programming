"""
AtCoder statistics provider using public profile page scraping.
"""

import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


def fetch_atcoder_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch AtCoder statistics from the public profile page.
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

        # Extract rating
        rating_match = re.search(r'Rating:\s*<span[^>]*>(\d+)', html)
        if rating_match:
            metrics["rating"] = int(rating_match.group(1))

        # Extract highest rating
        highest_match = re.search(r'Highest:\s*<span[^>]*>(\d+)', html)
        if highest_match:
            metrics["highest_rating"] = int(highest_match.group(1))

        # Extract rank if available
        rank_match = re.search(r'Rank:\s*<span[^>]*>(\d+)', html)
        if rank_match:
            metrics["rank"] = int(rank_match.group(1))

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="AtCoder",
            username=username,
            profile_url=profile_url,
            metrics=metrics,
            status=status,
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.now(timezone.utc).isoformat(),
            error=None if metrics else "Could not extract statistics from profile page",
        )

    except urllib.error.URLError as e:
        return PlatformStats(
            platform="AtCoder",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Network error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.now(timezone.utc).isoformat(),
        )
    except Exception as e:
        return PlatformStats(
            platform="AtCoder",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Unexpected error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.now(timezone.utc).isoformat(),
        )
