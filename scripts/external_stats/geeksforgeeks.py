"""
GeeksforGeeks statistics provider.

GeeksforGeeks does not have a reliable official public API for profile statistics.
"""

from .models import PlatformStats, RetrievalStatus


def fetch_geeksforgeeks_stats(username: str, profile_url: str) -> PlatformStats:
    """
    GeeksforGeeks statistics provider.

    GeeksforGeeks does not have a reliable official public API for profile statistics.
    Mark as unavailable.
    """
    return PlatformStats(
        platform="GeeksforGeeks",
        username=username,
        profile_url=profile_url,
        status=RetrievalStatus.UNAVAILABLE,
        error="GeeksforGeeks does not have a reliable official public API for profile statistics",
        source="none",
    )
