"""
HackerRank statistics provider.

HackerRank does not have a reliable official public API for profile statistics.
"""

from .models import PlatformStats, RetrievalStatus


def fetch_hackerrank_stats(username: str, profile_url: str) -> PlatformStats:
    """
    HackerRank statistics provider.

    HackerRank does not have a reliable official public API for profile statistics.
    Mark as unavailable.
    """
    return PlatformStats(
        platform="HackerRank",
        username=username,
        profile_url=profile_url,
        status=RetrievalStatus.UNAVAILABLE,
        error="HackerRank does not have a reliable official public API for profile statistics",
        source="none",
    )
