# External Statistics Methodology

This document explains how external platform statistics are fetched, the data sources used, rate limits, and the philosophy behind live vs snapshot data.

## Overview

The repository automatically fetches public profile statistics from competitive programming platforms using official APIs, public GraphQL endpoints, and structured profile data. These statistics are independent of the solution files stored in this repository.

## Running the Script

To manually update external statistics:

```bash
python3 scripts/external_stats.py
```

This will:
1. Discover profile URLs from repository README files
2. Fetch statistics from each platform
3. Generate `docs/generated/external-stats.json`
4. Generate `docs/generated/external-stats.md`
5. Update the External Platform Statistics section in `README.md`

## Platform-Specific Methods

### Codeforces

**Status**: 🟢 Live (Official API)

**Method**: Official Codeforces API

**API Endpoints**:
- `user.info` - Basic profile information (rating, rank, max rating)
- `user.status` - Submission history (for unique solved count)

**Rate Limit**: ~1 request per 2 seconds (enforced with 2-second delay between calls)

**Implementation Details**:
- Uses `urllib.request` with retry logic (3 attempts with exponential backoff)
- Counts unique accepted problems by tracking `contestId_problemIndex` pairs
- Failure of this platform does not prevent other platforms from updating

**Documentation**: https://codeforces.com/apiHelp/methods?locale=en

**Example**:
```python
# API call 1: user.info
url = "https://codeforces.com/api/user.info?handles=prathamkashyap"
# 2-second delay enforced
# API call 2: user.status
url = "https://codeforces.com/api/user.status?handle=prathamkashyap"
```

---

### LeetCode

**Status**: 🟢 Live (Public GraphQL API with browser fallback)

**Method**: Public GraphQL API (primary), browser rendering (fallback)

**GraphQL Queries**:
- `userPublicProfile` - Profile ranking, reputation, solution count
- `userBadges` - Earned badges and active badge
- `userCalendar` - Streak information and active days
- `languageStats` - Language breakdown by problems solved
- `userContestRanking` - Contest rating and global ranking
- `recentAcSubmissions` - Recent accepted submissions

**Rate Limit**: LeetCode's public GraphQL does not have documented rate limits for basic queries

**Implementation Details**:
- Uses `urllib.request` with standard browser headers
- Multiple focused GraphQL queries for different metric categories
- Falls back to Playwright browser rendering if GraphQL fails (optional, requires `playwright` package)
- Network capture mode intercepts GraphQL responses from browser network requests

**Fallback**: If GraphQL fails, attempts browser rendering to extract data from rendered page

**Example GraphQL Query**:
```graphql
query userPublicProfile($username: String!) {
    matchedUser(username: $username) {
        username
        profile {
            ranking
            reputation
            solutionCount
        }
        submitStats {
            acSubmissionNum {
                difficulty
                count
                submissions
            }
        }
    }
}
```

---

### CodeChef

**Status**: 🟢 Live (Embedded structured state with browser fallback)

**Method**: HTML parsing of embedded Drupal.settings JSON (primary), browser rendering (fallback)

**Data Sources**:
- Embedded `Drupal.settings` JSON in profile HTML (rating history, DSA Monday ratings)
- Semantic HTML markup (total problems solved, stars, league)
- Browser rendering fallback (for missing data)

**Rate Limit**: No documented rate limit for profile page access

**Implementation Details**:
- Fetches profile HTML with standard browser headers
- Parses `jQuery.extend(Drupal.settings, {...})` block for rating history
- Extracts current rating, max rating, global rank, DSA Monday rating/rank
- Uses regex for semantic markup (total solved, stars, league)
- Falls back to Playwright browser rendering if primary method fails

**Data Extraction**:
```python
# Extract Drupal.settings JSON
pattern = r"jQuery\.extend\(Drupal\.settings,\s*({.+?})\);"
# Parse rating history from date_versus_rating
ratings = drupal_data["date_versus_rating"]["all"]
current_rating = ratings[-1]["rating"]
```

---

### HackerRank

**Status**: 🟢 Live (Public REST API)

**Method**: Public REST API endpoints

**API Endpoints**:
- `/rest/hackers/{username}/badges` - Skill badges, star ratings, challenge counts
- `/rest/hackers/{username}/skills` - Verified skills list
- `/rest/hackers/{username}/scores_elo` - Track scores and ranks
- `/rest/contests/master/hackers/{username}/profile` - User profile metadata

**Rate Limit**: No documented rate limit for public REST endpoints

**Implementation Details**:
- Uses `urllib.request` with standard browser headers
- Separates earned skill badges (stars > 0) from tutorial/unearned tracks
- Extracts specific high-value ranks (SQL, Problem Solving)
- Aggregates total stars and total challenges solved

**Example API Call**:
```python
url = "https://www.hackerrank.com/rest/hackers/prathamkashyap/badges"
headers = {
    "User-Agent": "Mozilla/5.0 ...",
    "Referer": "https://www.hackerrank.com/profile/prathamkashyap"
}
```

---

### HackerEarth

**Status**: 🟢 Live (Public API with browser rendering supplement)

**Method**: Public JSON API (primary), browser rendering (supplementary)

**API Endpoints**:
- `/api/community/user/profile/{username}/metrics/` - Points, solved count, submissions
- `/api/community/user/profile/{username}/badges/` - Badge list

**Browser Rendering**: Track rankings, top percentiles, star levels

**Rate Limit**: No documented rate limit for public community API

**Implementation Details**:
- Primary metrics and badges from public JSON API
- Browser rendering supplements with track rankings (Basic Programming, Algorithms)
- Parses track leaderboard tables with structural verification
- Extracts top percentiles from profile text
- Uses bounds validation to prevent incorrect metric assignment

**Data Validation**:
- Rank bounds: 1 to 10,000,000
- Points bounds: 0 to 100,000
- Header order verification for text-based extraction

---

### GeeksforGeeks

**Status**: 🟢 Live (Embedded state with API supplement)

**Method**: Embedded structured data (primary), API supplement (partial)

**Data Sources**:
- Embedded profile state in HTML (coding score, solved counts, difficulty breakdown)
- Public API endpoints (partial coverage)

**Rate Limit**: No documented rate limit

**Implementation Details**:
- Extracts coding score, total solved, difficulty breakdown from embedded JSON
- Tracks POTD (Problem of the Day) solved and streak information
- Monitors 2026 activity (submissions, active days)
- Falls back to snapshot if live fetch fails

**Fallback**: Uses verified screenshot snapshots if live endpoints become unavailable

---

## Error Handling & Resilience

### Retry Logic

Network requests use exponential backoff for transient errors:
- Maximum retries: 3
- Initial delay: 1 second
- Backoff factor: 2.0 (delays: 1s, 2s, 4s)
- Retryable errors: `URLError`, `HTTPError`, `TimeoutError`, `ConnectionError`

### Platform Independence

Each platform is fetched independently:
- Failure of one platform does not prevent others from updating
- Partial success is acceptable for scheduled workflows
- Each platform's errors are logged separately

### Snapshot Fallback

If live retrieval fails (UNAVAILABLE or FAILED status):
- Attempts to load from verified snapshot data
- Snapshot data is clearly marked with `source_type: "snapshot"`
- Timestamps indicate when snapshot was last verified

## Live vs Snapshot Philosophy

### Live Data (🟢)

- Fetched directly from public APIs, GraphQL endpoints, or structured profiles
- Represents current platform state
- Includes exact timestamp of retrieval
- Preferred when available and reliable

### Snapshot Data (📸)

- Used when live endpoints are unavailable, shielded, or unreliable
- Based on verified screenshots or historical captures
- Clearly marked as snapshot in generated output
- Last verification timestamp is preserved
- Updated manually when live access becomes available

### Principle

**Never merge snapshot data into live records.** Live and snapshot data are kept strictly separate to maintain transparency about data freshness and source.

## Rate Limiting

### Codeforces

- **Enforced**: 2-second delay between API calls
- **Reason**: Official API has ~1 request per 2 second rate limit
- **Implementation**: `rate_limit_delay(2.0)` between `user.info` and `user.status` calls

### Other Platforms

- No documented rate limits for public profile/statistics endpoints
- Standard browser headers used to avoid blocking
- Retry logic handles transient network errors

## Generated Files

### external-stats.json

Machine-readable JSON with all platform statistics:
```json
[
  {
    "platform": "Codeforces",
    "username": "prathamkashyap",
    "profile_url": "https://codeforces.com/profile/prathamkashyap",
    "metrics": {
      "rating": 815,
      "rank": "newbie",
      "solved": 408
    },
    "source": "official_api",
    "source_type": "live",
    "retrieval_method": "api",
    "retrieved_at": "2026-10-24T12:00:00Z",
    "status": "success"
  }
]
```

### external-stats.md

Human-readable Markdown with:
- Platform summary table
- Detailed platform profiles
- Methodology notes
- Status badges (🟢 live, 📸 snapshot)

### README.md Updates

The "External Platform Statistics" section is automatically updated with:
- Current statistics for each platform
- Live/snapshot status indicators
- Key highlights
- Links to detailed external-stats.md

## Scheduled Updates

### GitHub Actions Workflow

**File**: `.github/workflows/update-external-stats.yml`

**Schedule**: Daily at 00:00 UTC

**Manual Trigger**: Available via `workflow_dispatch`

**Behavior**:
- Runs `scripts/external_stats.py`
- Continues even if some platforms fail (partial success acceptable)
- Auto-commits generated files with conventional commit message
- Commit message: `chore(stats): update external platform statistics`

**Files Committed**:
- `docs/generated/external-stats.json`
- `docs/generated/external-stats.md`
- `README.md` (External Platform Statistics section)

## Data Philosophy

### No Misleading Totals

Solved counts are **never summed across platforms**. Problem overlaps between platforms make a mathematically sound "total unique solved" impossible. Platform numbers are kept distinct and verifiable.

### Repository Separation

External platform statistics represent actual progress on external accounts and are tracked independently from the solution files stored in this repository. Local repository statistics (file counts, lines of code) are tracked separately in `docs/generated/stats.md`.

### Transparency

Every metric includes:
- Source (API endpoint, GraphQL, embedded state, snapshot)
- Source type (live or snapshot)
- Retrieval method
- Timestamp
- Status (success, partial, unavailable, failed)

## Troubleshooting

### Script Fails to Run

1. Check Python 3 is installed: `python3 --version`
2. Verify profile URLs exist in README files
3. Check network connectivity

### Specific Platform Fails

1. Check the platform's profile is public
2. Verify username in URL matches actual handle
3. Check if platform has changed their API/profile structure
4. Review error message in generated external-stats.md

### Rate Limit Errors

- Increase delay in `CODEFORCES_RATE_LIMIT_DELAY` if needed
- Add delays for other platforms if they implement rate limits

### Snapshot Not Loading

- Verify snapshot data exists in `scripts/external_stats/snapshots/`
- Check snapshot filename matches platform and username pattern
- Update snapshot with current verified data

## Future Improvements

- Add caching to avoid unnecessary refetches
- Investigate additional public endpoints for better LeetCode coverage
- Explore official APIs for platforms currently using embedded state
- Add historical tracking for rating changes over time
