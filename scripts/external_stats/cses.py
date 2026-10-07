"""
CSES statistics provider.

CSES does not have user profiles in the same way as other platforms.
"""

from .models import PlatformStats, RetrievalStatus


def fetch_cses_stats(username: str, profile_url: str) -> PlatformStats:
    """
    CSES statistics provider.

    CSES does not have user profiles with public statistics.
    Mark as unavailable.
    """
    return PlatformStats(
        platform="CSES",
        username="",
        profile_url="https://cses.fi/problemset/",
        status=RetrievalStatus.UNAVAILABLE,
        error="CSES does not have user profiles with public statistics",
        source="none",
    )
