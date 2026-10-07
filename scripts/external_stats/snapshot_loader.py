"""
Load screenshot-derived statistics as reference data and fallback.
"""

import json
import os
from typing import Dict, Any, Optional
from datetime import datetime, timezone
from .models import PlatformStats, RetrievalStatus


SNAPSHOT_FILE = os.path.join(os.path.dirname(__file__), "snapshot_data.json")


def load_snapshot_data() -> Dict[str, Any]:
    """
    Load snapshot data from the snapshot_data.json file.
    """
    try:
        with open(SNAPSHOT_FILE, "r") as f:
            return json.load(f)
    except (FileNotFoundError, json.JSONDecodeError):
        return {}


def get_snapshot_stats(platform: str, username: str, profile_url: str) -> Optional[PlatformStats]:
    """
    Get snapshot statistics for a platform if available.
    Returns None if no snapshot data exists for this platform.
    """
    snapshot_data = load_snapshot_data()
    platforms = snapshot_data.get("platforms", {})

    platform_key = platform.lower().replace(" ", "")

    platform_snapshot = platforms.get(platform_key)
    if not platform_snapshot:
        return None

    # Verify username matches
    if platform_snapshot.get("username") != username:
        return None

    metrics = platform_snapshot.get("metrics", {})
    if not metrics:
        return None

    capture_date = platform_snapshot.get("capture_date", datetime.now(timezone.utc).strftime("%Y-%m-%d"))

    return PlatformStats(
        platform=platform,
        username=username,
        profile_url=profile_url,
        metrics=metrics,
        source="screenshot_snapshot",
        source_type="screenshot_snapshot",
        retrieval_method="screenshot_snapshot",
        retrieved_at=capture_date,
        status=RetrievalStatus.SUCCESS,
        error=None,
    )
