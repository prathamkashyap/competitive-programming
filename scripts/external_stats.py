#!/usr/bin/env python3
"""
External competitive programming profile statistics generator.

This script discovers profile URLs from the repository and fetches public statistics
from external competitive programming platforms.

Usage:
    python scripts/external_stats.py

The script will:
1. Discover profile URLs from repository README files
2. Fetch public statistics where APIs are available
3. Generate docs/generated/external-stats.json
4. Generate docs/generated/external-stats.md
"""

import sys
from pathlib import Path

# Add the external_stats package to the path
sys.path.insert(0, str(Path(__file__).parent))

from external_stats.external_stats import main

if __name__ == "__main__":
    main()
