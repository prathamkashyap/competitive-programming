"""
HackerEarth statistics provider.

HackerEarth does not have a reliable official public API for profile statistics.
"""

from .models import PlatformStats, RetrievalStatus


def fetch_hackerearth_stats(username: str, profile_url: str) -> PlatformStats:
    """
    HackerEarth statistics provider.

    HackerEarth does not have a reliable official public API for profile statistics.
    Mark as unavailable.
    """
    return PlatformStats(
        platform="HackerEarth",
        username=username,
        profile_url=profile_url,
        status=RetrievalStatus.UNAVAILABLE,
        error="HackerEarth does not have a reliable official public API for profile statistics",
        source="none",
    )
