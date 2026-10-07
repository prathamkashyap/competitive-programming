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

| Platform | Status | Source | Retrieval Method | Notes |
|----------|--------|--------|------------------|-------|
| Codeforces | ✅ Success | Official API | API | Retrieves rating, rank, solved count |
| HackerRank | ✅ Success | Public Profile | Scrape | Retrieves badges, stars, certifications |
| LeetCode | ⊘ Unavailable | Public Profile | Scrape | Could not extract statistics from page |
| CodeChef | ⊘ Unavailable | Public Profile | Scrape | Could not extract statistics from page |
| HackerEarth | ⊘ Unavailable | Public Profile | Scrape | Could not extract statistics from page |
| GeeksforGeeks | ⊘ Unavailable | Public Profile | Scrape | Could not extract statistics from page |
| AtCoder | - | - | - | No profile URL in repository |
| CSES | ⊘ Unavailable | None | None | No user profiles with public statistics |

## Status Meanings

- **success**: Statistics successfully retrieved from the platform
- **partial**: Some statistics retrieved, but not all
- **unavailable**: Platform could not retrieve statistics (no data in page or no profile)
- **unconfigured**: No provider available for this platform
- **failed**: Error occurred during retrieval (network, etc.)

## How to Refresh Statistics

Run the external statistics generator:

```bash
python scripts/external_stats.py
```

This will:
1. Discover profiles from repository READMEs
2. Fetch statistics from platforms with available APIs or scrape public profiles
3. Generate `docs/generated/external-stats.json`
4. Generate `docs/generated/external-stats.md`

## Important Distinction

**External account statistics** (from external-stats.md):
- Codeforces: 374 solved, rating 815
- HackerRank: 2530 badges, 22 stars, 20 certifications
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
    ├── leetcode.py            # LeetCode provider (public profile scrape)
    ├── codechef.py            # CodeChef provider (public profile scrape)
    ├── hackerearth.py         # HackerEarth provider (public profile scrape)
    ├── hackerrank.py          # HackerRank provider (public profile scrape)
    ├── geeksforgeeks.py       # GeeksforGeeks provider (public profile scrape)
    ├── atcoder.py             # AtCoder provider (public profile scrape)
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

## Retrieval Methods

1. **Official API** - Preferred when available (e.g., Codeforces)
2. **Public Profile Scrape** - When no API exists, attempt to extract visible data from the public profile page
3. **Browser Rendering** - For client-rendered pages (not yet implemented, would require additional tools)

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

**HackerRank** (via public profile scrape):
- Username: prathamkashyap
- Badges: 2530
- Stars: 22
- Certifications: 20
- Status: success

**Other platforms**: unavailable - could not extract statistics from public profile pages

## Why Some Platforms Are Unavailable

The scraping approach uses simple regex patterns to extract data from HTML. Many modern platforms:
- Use client-side JavaScript rendering (data not in initial HTML)
- Have complex DOM structures that require more sophisticated parsing
- May require JavaScript execution to load statistics

Future improvements could use browser automation tools (e.g., Selenium, Playwright) to handle client-rendered pages, but this adds complexity and dependencies.

## Alternative Approach

For platforms that cannot be scraped, you can:
1. Manually update the profile URL in the README to point to a page with visible statistics
2. Add a manual configuration file with key statistics (less ideal)
3. Wait for official API availability
4. Use third-party APIs if available and reliable
