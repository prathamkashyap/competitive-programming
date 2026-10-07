"""
CSES statistics provider.

CSES does not have user profiles with public statistics.
"""

from typing import Dict, Any, Optional
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


def fetch_cses_stats(username: str, profile_url: str) -> PlatformStats:
    """
    CSES statistics provider.

    CSES does not have user profiles with public statistics.
    """
    return PlatformStats(
        platform="CSES",
        username="",
        profile_url="https://cses.fi/problemset/",
        metrics={},
        status=RetrievalStatus.UNAVAILABLE,
        error="CSES does not have user profiles with public statistics",
        source="none",
        retrieval_method="none",
        retrieved_at=datetime.now(timezone.utc).isoformat(),
    )
