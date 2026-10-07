"""
LeetCode statistics provider.

LeetCode does not have a clean official public API for profile statistics.
This provider attempts to mark it as unavailable rather than scraping.
"""

from .models import PlatformStats, RetrievalStatus


def fetch_leetcode_stats(username: str, profile_url: str) -> PlatformStats:
    """
    LeetCode statistics provider.

    LeetCode does not have a reliable official public API for profile statistics.
    Scraping would be fragile and may violate terms of service.
    Mark as unavailable.
    """
    return PlatformStats(
        platform="LeetCode",
        username=username,
        profile_url=profile_url,
        status=RetrievalStatus.UNAVAILABLE,
        error="LeetCode does not have a reliable official public API for profile statistics",
        source="none",
    )
