"""
HackerRank statistics provider using public profile page scraping.
"""

import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_hackerrank_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch HackerRank statistics from the public profile page.
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

        # Extract badges - HackerRank shows badges as icons with counts
        # Look for badge counts in the page
        badge_matches = re.findall(r'(\d+)\s*badges?', html, re.IGNORECASE)
        if badge_matches:
            metrics["badges"] = sum(int(b) for b in badge_matches)

        # Extract stars/points if available
        stars_match = re.search(r'(\d+)\s*stars', html, re.IGNORECASE)
        if stars_match:
            metrics["stars"] = int(stars_match.group(1))

        # Extract certifications if mentioned
        cert_match = re.search(r'(\d+)\s*certifications?', html, re.IGNORECASE)
        if cert_match:
            metrics["certifications"] = int(cert_match.group(1))

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="HackerRank",
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
            platform="HackerRank",
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
            platform="HackerRank",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Unexpected error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
        )
