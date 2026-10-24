# 🔧 Repository Automation Scripts ⚡

This directory contains scripts for generating statistics, validating code, and fetching external platform data.

---

## 📋 Available Scripts

### 📊 generate_stats.py

Scans the repository and generates local statistics from the filesystem.

**What it does:**
- Counts code files by language, platform, and category
- Generates problem index with metadata
- Creates `docs/generated/stats.md`, `docs/generated/problem-index.md`, and `docs/generated/problem-index.json`

**Usage:**
```bash
python3 scripts/generate_stats.py
```

**Output:**
- `docs/generated/stats.md` - Repository statistics in markdown
- `docs/generated/problem-index.md` - Problem index in markdown
- `docs/generated/problem-index.json` - Problem index in JSON

---

### 🌐 external_stats.py

Fetches live statistics from external competitive programming platforms.

**What it does:**
- Discovers profile URLs from README files
- Fetches statistics from Codeforces, LeetCode, CodeChef, HackerRank, HackerEarth, GeeksforGeeks
- Uses official APIs, public GraphQL, and structured profiles
- Generates badges and updates README with platform statistics

**Usage:**
```bash
python3 scripts/external_stats.py
```

**Output:**
- `docs/generated/external-stats.json` - Platform statistics in JSON
- `docs/generated/external-stats.md` - Platform statistics in markdown
- `docs/generated/badges/` - SVG badges for README
- Updated `README.md` with platform statistics

**Platform methods:**
- Codeforces: Official API (rate limited to 1 req/2s)
- LeetCode: Public GraphQL API with browser fallback
- CodeChef: Embedded Drupal.settings JSON
- HackerRank: Public REST API
- HackerEarth: Public API with browser supplement
- GeeksforGeeks: Embedded state with API supplement

See [docs/STATS_METHODOLOGY.md](../docs/STATS_METHODOLOGY.md) for detailed methodology.

---

### ✅ validate_cpp.py

Validates that all C++ solution files compile correctly.

**What it does:**
- Finds all C++ files (.cpp, .cc, .cxx)
- Attempts syntax-only compilation to avoid linker conflicts
- Reports compilation errors
- Skips files with local infrastructure issues (e.g., modified bits/stdc++.h)

**Usage:**
```bash
python3 scripts/validate_cpp.py
```

**Compiler requirements:**
- g++, clang++, or c++ with C++20 support
- On macOS: `xcode-select --install`
- On Ubuntu/Debian: `sudo apt install g++`

---

## 🤖 GitHub Actions

The repository uses two GitHub Actions workflows:

### .github/workflows/cpp-validation.yml ✅

Runs on push and pull request to validate C++ compilation.

**Triggers:**
- Push to main
- Pull requests to main
- Changes to C++ files, templates, scripts, tests, or workflow

**Steps:**
1. Verify C++ compiler
2. Run unit tests
3. Run statistics generator
4. Run C++ validation

### .github/workflows/update-external-stats.yml 📊

Runs daily at 00:00 UTC and on manual trigger to update external platform statistics.

**Triggers:**
- Schedule: `0 0 * * *` (daily at 00:00 UTC)
- Manual: `workflow_dispatch` (trigger from GitHub Actions UI)

**Steps:**
1. Run statistics generator
2. Run external statistics generator
3. Commit generated files (badges, external-stats JSON/MD, README)
4. Push changes

**Commit message:** `chore(stats): update external platform statistics`

---

## 🧠 Quick Reference

| 🎯 Script | 📖 Purpose | ⏱️ Runtime |
| :--- | :--- | :--- |
| `generate_stats.py` | Local repository statistics | ~1s |
| `external_stats.py` | Fetch external platform stats | ~10-30s |
| `validate_cpp.py` | Validate C++ compilation | ~30-60s |

---

## 💡 Tips

- Run `generate_stats.py` after adding new solutions to update counts
- Run `external_stats.py` manually if you need fresh stats before the daily run
- Run `validate_cpp.py` locally before pushing to catch compilation errors early

---

[← Back to Main Repository](../README.md)
