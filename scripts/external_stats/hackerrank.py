"""
HackerRank statistics provider using browser-rendered profile retrieval.
"""

import re
import urllib.request
import urllib.error
from typing import Dict, Any, Optional
from datetime import datetime
from .models import PlatformStats, RetrievalStatus


def fetch_hackerrank_stats(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch HackerRank statistics using browser rendering for better badge extraction.

    Based on screenshot analysis: profile shows 5-star badges for skills.
    """
    # Try browser rendering first for better extraction
    try:
        from .browser_renderer import is_playwright_available, fetch_rendered_page, extract_from_text

        if is_playwright_available():
            return fetch_hackerrank_with_browser(username, profile_url)
    except ImportError:
        pass
    except Exception as e:
        # Browser rendering failed, fall back to simple scrape
        pass

    # Fall back to simple scrape
    return fetch_hackerrank_simple(username, profile_url)


def fetch_hackerrank_with_browser(username: str, profile_url: str) -> PlatformStats:
    """
    Fetch HackerRank statistics using browser rendering with CSS selectors.
    """
    import asyncio
    from .browser_renderer import fetch_rendered_page, extract_from_text

    async def _fetch():
        page_data = await fetch_rendered_page(
            profile_url,
            wait_selector=None,
            wait_timeout=30000,
            capture_network=False,
        )

        metrics = {}

        # Extract from rendered text with improved patterns
        text_patterns = {
            "certifications": r"(\d+)\s*certifications?",
            "profile_completion": r"(\d+)%\s*complete",
        }

        text_metrics = extract_from_text(page_data["text"], text_patterns)
        metrics.update(text_metrics)

        # Try to extract skill badges by looking for 5-star patterns
        # Based on screenshot: badges show skill names with 5 stars
        star_5_matches = re.findall(r"([A-Za-z]+(?:\s+[A-Za-z]+)*)\s*(?:★|⭐){5}", page_data["text"])
        if star_5_matches:
            metrics["skill_badges"] = len(star_5_matches)
            metrics["skills"] = [skill.strip() for skill in star_5_matches]

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="HackerRank",
            username=username,
            profile_url=profile_url,
            metrics=metrics,
            status=status,
            source="public_profile",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.utcnow().isoformat(),
            error=None if metrics else "Could not extract statistics from rendered profile",
        )

    try:
        return asyncio.run(_fetch())
    except Exception as e:
        return PlatformStats(
            platform="HackerRank",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Browser rendering error: {str(e)}",
            source="public_profile",
            retrieval_method="rendered_profile",
            retrieved_at=datetime.utcnow().isoformat(),
        )


def fetch_hackerrank_simple(username: str, profile_url: str) -> PlatformStats:
    """
    Fallback: simple HTTP scrape without browser rendering.
    """
    try:
        headers = {
            'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36'
        }
        req = urllib.request.Request(profile_url, headers=headers)

        with urllib.request.urlopen(req, timeout=10) as response:
            html = response.read().decode('utf-8')

        metrics = {}

        # Extract certifications
        cert_match = re.search(r'(\d+)\s*certifications?', html, re.IGNORECASE)
        if cert_match:
            count = int(cert_match.group(1))
            if count < 100:  # Sanity check
                metrics["certifications"] = count

        # Extract profile completion percentage
        completion_match = re.search(r'(\d+)%\s*complete', html, re.IGNORECASE)
        if completion_match:
            metrics["profile_completion"] = int(completion_match.group(1))

        # Determine status
        if metrics:
            status = RetrievalStatus.SUCCESS
        else:
            status = RetrievalStatus.UNAVAILABLE
            metrics = {}

        return PlatformStats(
            platform="HackerRank",
            username=username,
            profile_url=profile_url,
            metrics=metrics,
            status=status,
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
            error=None if metrics else "Could not extract statistics from profile page",
        )

    except urllib.error.URLError as e:
        return PlatformStats(
            platform="HackerRank",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Network error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
        )
    except Exception as e:
        return PlatformStats(
            platform="HackerRank",
            username=username,
            profile_url=profile_url,
            status=RetrievalStatus.FAILED,
            error=f"Unexpected error: {str(e)}",
            source="public_profile",
            retrieval_method="scrape",
            retrieved_at=datetime.utcnow().isoformat(),
        )
