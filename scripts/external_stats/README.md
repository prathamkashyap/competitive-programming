# External Statistics Documentation

## Overview

The external statistics system retrieves public profile information from competitive programming platforms and keeps it separate from the repository's actual solution files.

## Browser Rendering Support

For client-rendered profile pages (LeetCode, CodeChef, HackerEarth, GeeksforGeeks), the system can use browser rendering to extract data that is not available in the initial HTML.

### Installing Browser Support

To enable browser rendering:

1. Install dependencies:
   ```bash
   pip3 install -r requirements.txt
   ```

2. Install Playwright browser:
   ```bash
   playwright install chromium
   ```

### Fallback Behavior

If Playwright is not installed, the system will:
- Attempt simple HTTP scraping as a fallback
- Mark platforms as unavailable if data cannot be extracted from static HTML
- Continue to work for platforms with official APIs (Codeforces) or static profiles (HackerRank)

Browser rendering is optional. The system will function without it, but may not retrieve data from client-rendered pages.

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
| CodeChef | ✅ Success | Public Profile | Rendered Profile | Retrieves rating, global rank via browser rendering |
| HackerRank | ✅ Success | Public Profile | Scrape | Retrieves badges, stars, certifications |
| LeetCode | ⊘ Unavailable | Public Profile | Rendered Profile | Could not extract statistics from rendered page |
| HackerEarth | ⊘ Unavailable | Public Profile | Rendered Profile | Could not extract statistics from rendered page |
| GeeksforGeeks | ⊘ Unavailable | Public Profile | Rendered Profile | Could not extract statistics from rendered page |
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
3. **Browser Rendering** - For client-rendered pages using Playwright (requires `pip3 install -r requirements.txt` and `playwright install chromium`)
4. **Network Inspection** - Capture and inspect public network requests (XHR, fetch, JSON, GraphQL) during page rendering to extract structured data

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

**CodeChef** (via browser rendering):
- Username: prathamkashyap
- Rating: 922
- Max Rating: 922
- Global Rank: 17165
- Status: success

**HackerRank** (via public profile scrape with semantic verification):
- Username: prathamkashyap
- Badges: 22 (semantically verified from profile context)
- Certifications: 20
- Status: success

**Other platforms**: unavailable - could not extract statistics from rendered profiles

## Browser Rendering Limitations

Despite browser rendering with Playwright and network inspection, three platforms remain unavailable:

**LeetCode**: The page renders successfully and network requests were captured. However, the specific GraphQL/JSON data path for user statistics could not be reliably identified in the captured responses. The embedded Next.js state structure is complex and requires more specific reverse engineering. The visible text extraction patterns also did not match the rendered page structure.

**HackerEarth**: The page renders and network requests were captured, but no structured JSON/GraphQL responses containing profile statistics were found in the public network traffic. The statistics are likely loaded through complex JavaScript or require authenticated endpoints. Visible text patterns did not yield extractable data.

**GeeksforGeeks**: Similar to HackerEarth - the page renders and network requests were captured, but no structured public responses containing profile statistics were found. The site may use private APIs or complex client-side state management that is not exposed in public network traffic.

These limitations are due to:
- Complex GraphQL/JSON data structures requiring site-specific reverse engineering
- Statistics potentially loaded through authenticated or private endpoints
- Proprietary client-side state management not exposed in public network traffic
- Evolving page structures requiring ongoing maintenance

**Network Inspection Added**: The system now captures and inspects public network requests (XHR, fetch, JSON, GraphQL) during page rendering. This allows extraction from structured public responses when available, but the three platforms above either don't expose profile data in public network requests or use complex data paths that require more specific reverse engineering.
