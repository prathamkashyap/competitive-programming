"""
AtCoder statistics provider.

AtCoder does not have a reliable official public API for profile statistics.
"""

from .models import PlatformStats, RetrievalStatus


def fetch_atcoder_stats(username: str, profile_url: str) -> PlatformStats:
    """
    AtCoder statistics provider.

    AtCoder does not have a reliable official public API for profile statistics.
    Mark as unavailable.
    """
    return PlatformStats(
        platform="AtCoder",
        username=username,
        profile_url=profile_url,
        status=RetrievalStatus.UNAVAILABLE,
        error="AtCoder does not have a reliable official public API for profile statistics",
        source="none",
    )
