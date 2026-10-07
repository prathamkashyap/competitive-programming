"""
Profile discovery from repository Markdown files.
"""

import re
from pathlib import Path
from typing import Dict, Optional, Tuple
from urllib.parse import urlparse


# Platform URL patterns
PLATFORM_PATTERNS = {
    "codeforces": [
        r"https?://codeforces\.com/profile/([a-zA-Z0-9_\-\.]+)",
        r"https?://codeforces\.com/profile/([a-zA-Z0-9_\-\.]+)/?",
    ],
    "leetcode": [
        r"https?://leetcode\.com/u/([a-zA-Z0-9_\-\.]+)",
        r"https?://leetcode\.com/u/([a-zA-Z0-9_\-\.]+)/?",
    ],
    "codechef": [
        r"https?://www\.codechef\.com/users/([a-zA-Z0-9_\-\.]+)",
        r"https?://www\.codechef\.com/users/([a-zA-Z0-9_\-\.]+)/?",
    ],
    "hackerearth": [
        r"https?://www\.hackerearth\.com/@([a-zA-Z0-9_\-\.]+)",
        r"https?://www\.hackerearth\.com/@([a-zA-Z0-9_\-\.]+)/?",
    ],
    "hackerrank": [
        r"https?://www\.hackerrank\.com/profile/([a-zA-Z0-9_\-\.]+)",
        r"https?://www\.hackerrank\.com/profile/([a-zA-Z0-9_\-\.]+)/?",
    ],
    "geeksforgeeks": [
        r"https?://www\.geeksforgeeks\.org/profile/([a-zA-Z0-9_\-\.]+)",
        r"https?://www\.geeksforgeeks\.org/profile/([a-zA-Z0-9_\-\.]+)/?",
    ],
    "atcoder": [
        r"https?://atcoder\.jp/users/([a-zA-Z0-9_\-\.]+)",
        r"https?://atcoder\.jp/users/([a-zA-Z0-9_\-\.]+)/?",
    ],
    "cses": [
        r"https?://cses\.fi/problemset/",  # CSES doesn't have user profiles in the same way
    ],
}


def extract_username_from_url(url: str, platform: str) -> Optional[str]:
    """
    Extract username from a profile URL for a given platform.
    Returns None if no match.
    """
    patterns = PLATFORM_PATTERNS.get(platform, [])
    for pattern in patterns:
        match = re.search(pattern, url)
        if match:
            # Extract the capture group
            if match.groups():
                return match.group(1)
    return None


def discover_profiles(repo_root: Path) -> Dict[str, Tuple[str, str]]:
    """
    Discover profile URLs from repository README files.

    Returns:
        Dict mapping platform name to (username, profile_url) tuple.
        Platforms without discoverable profiles are omitted.
    """
    profiles = {}

    # Files to search for profile links
    files_to_search = [
        repo_root / "README.md",
        repo_root / "leetcode" / "README.md",
        repo_root / "codechef" / "README.md",
        repo_root / "codeforces" / "README.md",
        repo_root / "hackerearth" / "README.md",
        repo_root / "hackerrank" / "README.md",
        repo_root / "geeksforgeeks" / "README.md",
        repo_root / "atcoder" / "README.md",
        repo_root / "cses" / "README.md",
    ]

    for file_path in files_to_search:
        if not file_path.exists():
            continue

        with open(file_path, 'r', encoding='utf-8') as f:
            content = f.read()

        # Extract all URLs from the file
        urls = re.findall(r'https?://[^\s\)]+', content)

        for url in urls:
            # Try to match against each platform
            for platform, patterns in PLATFORM_PATTERNS.items():
                if platform == "cses":
                    # CSES doesn't have user profiles
                    continue

                username = extract_username_from_url(url, platform)
                if username:
                    profiles[platform] = (username, url)
                    # Found a match for this platform, move to next URL
                    break

    return profiles


def get_profile_info(repo_root: Path) -> Dict[str, Dict[str, str]]:
    """
    Get profile information in a structured format.

    Returns:
        Dict with platform as key and dict with 'username' and 'profile_url'.
    """
    profiles = discover_profiles(repo_root)
    return {
        platform: {"username": username, "profile_url": url}
        for platform, (username, url) in profiles.items()
    }
