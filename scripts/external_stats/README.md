# External Statistics Documentation

## Overview

The external statistics system retrieves public profile information from competitive programming platforms and keeps it separate from the repository's actual solution files.

## How Profile Discovery Works

The system automatically discovers profile URLs from repository README files:

1. Scans README.md and platform-specific README files (leetcode/, codechef/, codeforces/, etc.)
2. Extracts URLs using platform-specific patterns
3. Extracts usernames from URLs
4. No manual username configuration required

If you update a profile URL in a README, the system will automatically discover the new username on the next refresh.

## Supported Platforms

| Platform | Status | Source | Notes |
|----------|--------|--------|-------|
| Codeforces | ✅ Success | Official API | Retrieves rating, rank, solved count |
| LeetCode | ⊘ Unavailable | None | No reliable official public API |
| CodeChef | ⊘ Unavailable | None | No reliable official public API |
| HackerEarth | ⊘ Unavailable | None | No reliable official public API |
| HackerRank | ⊘ Unavailable | None | No reliable official public API |
| GeeksforGeeks | ⊘ Unavailable | None | No reliable official public API |
| AtCoder | ⊘ Unavailable | None | No reliable official public API |
| CSES | ⊘ Unavailable | None | No user profiles with public statistics |

## Status Meanings

- **success**: Statistics successfully retrieved from the platform
- **unavailable**: Platform does not have a reliable official public API for statistics
- **unconfigured**: No provider available for this platform
- **failed**: Error occurred during retrieval (network, API error, etc.)

## How to Refresh Statistics

Run the external statistics generator:

```bash
python scripts/external_stats.py
```

This will:
1. Discover profiles from repository READMEs
2. Fetch statistics from platforms with available APIs
3. Generate `docs/generated/external-stats.json`
4. Generate `docs/generated/external-stats.md`

## Important Distinction

**External account statistics** (from external-stats.md):
- LeetCode solved: X
- Codeforces solved: Y
- CodeChef solved: Z
- These represent actual progress on external platforms

**Repository file statistics** (from stats.md):
- C++ solution files: 399
- Python solution files: 2
- Java solution files: 2
- Codeforces solutions in repository: 392
- These represent actual files in this GitHub repository

These are separate concepts and should never be combined.

## Architecture

```
scripts/
├── external_stats.py          # Main entry point
└── external_stats/
    ├── __init__.py            # Package initialization
    ├── models.py              # Data models (PlatformStats, RetrievalStatus)
    ├── discovery.py           # Profile URL discovery from READMEs
    ├── external_stats.py      # Orchestration and generation
    ├── codeforces.py          # Codeforces provider (official API)
    ├── leetcode.py            # LeetCode provider (unavailable)
    ├── codechef.py            # CodeChef provider (unavailable)
    ├── hackerearth.py         # HackerEarth provider (unavailable)
    ├── hackerrank.py          # HackerRank provider (unavailable)
    ├── geeksforgeeks.py       # GeeksforGeeks provider (unavailable)
    ├── atcoder.py             # AtCoder provider (unavailable)
    └── cses.py                # CSES provider (unavailable)
```

## Adding a New Platform

To add support for a new platform:

1. Add URL patterns to `discovery.py` in `PLATFORM_PATTERNS`
2. Create a new provider file (e.g., `newplatform.py`)
3. Implement `fetch_newplatform_stats(username, profile_url)` function
4. Add the provider to `PROVIDERS` dict in `external_stats.py`
5. Run the script to test

The provider should return a `PlatformStats` object with appropriate status and metrics.

## Security

- Only public APIs and public profile information are accessed
- No passwords, session cookies, or authentication tokens are used
- No CAPTCHA bypass or anti-bot circumvention
- Read-only access only
- No account modification or problem submission

## Current Retrieved Statistics

As of the last refresh:

**Codeforces** (via official API):
- Username: prathamkashyap
- Rating: 815
- Max Rating: 815
- Rank: newbie
- Solved: 374
- Status: success

All other platforms are marked as unavailable due to lack of reliable public APIs.
