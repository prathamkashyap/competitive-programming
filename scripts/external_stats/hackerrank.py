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

    Semantically verify metrics before labeling them.
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

        # Extract badges - look for badge count with clear context
        # HackerRank shows badge count in the profile
        badge_count = re.search(r'(\d+)\s*badges?\s*(?:earned|completed|unlocked)', html, re.IGNORECASE)
        if badge_count:
            metrics["badges"] = int(badge_count.group(1))
        else:
            # Fallback: just count the word "badge" near a number
            badge_match = re.search(r'(\d+)\s*badges?', html, re.IGNORECASE)
            if badge_match:
                # Only use if it's a reasonable number (not all badges on the platform)
                count = int(badge_match.group(1))
                if count < 10000:  # Sanity check
                    metrics["badges"] = count

        # Extract stars - look for star rating context
        stars_match = re.search(r'(\d+)\s*stars?', html, re.IGNORECASE)
        if stars_match:
            count = int(stars_match.group(1))
            if count <= 10:  # Stars are typically 1-5 or 1-10
                metrics["stars"] = count

        # Extract certifications - look for certification count
        cert_match = re.search(r'(\d+)\s*certifications?', html, re.IGNORECASE)
        if cert_match:
            count = int(cert_match.group(1))
            if count < 100:  # Sanity check
                metrics["certifications"] = count

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
