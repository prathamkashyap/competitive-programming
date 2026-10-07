"""
CodeChef statistics provider.

CodeChef does not have a reliable official public API for profile statistics.
"""

from .models import PlatformStats, RetrievalStatus


def fetch_codechef_stats(username: str, profile_url: str) -> PlatformStats:
    """
    CodeChef statistics provider.

    CodeChef does not have a reliable official public API for profile statistics.
    Mark as unavailable.
    """
    return PlatformStats(
        platform="CodeChef",
        username=username,
        profile_url=profile_url,
        status=RetrievalStatus.UNAVAILABLE,
        error="CodeChef does not have a reliable official public API for profile statistics",
        source="none",
    )
