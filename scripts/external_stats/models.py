"""
Data models for external platform statistics.
"""

from dataclasses import dataclass, field
from typing import Optional, Dict, Any
from enum import Enum
from datetime import datetime


class RetrievalStatus(Enum):
    """Status of external statistics retrieval."""
    SUCCESS = "success"
    PARTIAL = "partial"
    UNAVAILABLE = "unavailable"
    UNCONFIGURED = "unconfigured"
    FAILED = "failed"


@dataclass
class PlatformStats:
    """Statistics for a competitive programming platform."""
    platform: str
    username: str
    profile_url: str
    metrics: Dict[str, Any] = field(default_factory=dict)
    source: str = ""
    retrieval_method: str = ""
    retrieved_at: str = ""
    status: RetrievalStatus = RetrievalStatus.UNCONFIGURED
    error: Optional[str] = None

    def to_dict(self) -> Dict[str, Any]:
        """Convert to dictionary for JSON serialization."""
        return {
            "platform": self.platform,
            "username": self.username,
            "profile_url": self.profile_url,
            "metrics": self.metrics,
            "source": self.source,
            "retrieval_method": self.retrieval_method,
            "retrieved_at": self.retrieved_at,
            "status": self.status.value,
            "error": self.error,
        }
