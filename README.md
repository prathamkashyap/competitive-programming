# Competitive Programming & Algorithmic Problem Solving

A repository of algorithmic problem solutions, reusable templates, and algorithmic notes for competitive programming and interview preparation.

## What This Repository Contains

- **400+ Codeforces solutions** organized by difficulty rating (800-2000)
- **Reusable C++ templates** for common data structures and algorithms
- **Algorithmic notes** covering complexity, number theory, graphs, DP, and more
- **Multi-language support** with C++ as the primary language (Python and Java also available)

## Quick Navigation

- [Codeforces Solutions](codeforces/) - Problems organized by rating
- [Templates](templates/) - Reusable boilerplate and data structures
- [Notes](notes/) - Algorithmic theory and cheat sheets
- [Generated Statistics](docs/generated/stats.md) - Exact file counts and breakdowns
- [Problem Index](docs/generated/problem-index.md) - Complete solution index

## Repository Structure

```
competitive-programming/
├── codeforces/          # C++ solutions by difficulty rating
│   ├── 800/             # Fundamental problems
│   ├── 900/             # Easy problems
│   ├── 1000-2000/       # Intermediate to advanced
│   └── unrated_questions/
├── templates/           # Reusable templates
│   ├── cpp/             # C++ data structures
│   ├── python/          # Python utilities
│   └── java/            # Java fast I/O
├── notes/               # Algorithmic reference
├── docs/                # Documentation
│   └── generated/       # Auto-generated statistics
└── scripts/             # Repository automation
```

## Compilation

### C++20 Build

```bash
g++ -std=c++20 -O2 -Wall -Wextra solution.cpp -o solution
./solution < input.txt
```

### Fast I/O

```cpp
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // solve problem
}
```

## Templates

The repository includes tested templates for:

- **Fast I/O** - Optimized input/output for competitive programming
- **Disjoint Set Union (DSU)** - $O(\alpha(N))$ union-find with path compression
- **Segment Tree** - Point update, range query in $O(\log N)$
- **Fenwick Tree** - Binary indexed tree for prefix sums
- **Linear Sieve** - $O(N)$ prime sieve with smallest prime factor
- **Modular Arithmetic** - Fast exponentiation, modular inverse, combinations
- **Graph Traversal** - BFS, topological sort, Dijkstra
- **Prefix Sums** - Range sum queries and difference arrays
- **Sliding Window** - At-most-K distinct, bounded sums

See [templates/](templates/) for complete implementations.

## Notes

Algorithmic reference material:

- [Time Complexity & Limits](notes/complexity_and_limits.md) - Operations per second, integer boundaries
- [Number Theory](notes/number_theory.md) - Modular arithmetic, GCD, sieve
- [Bit Manipulation](notes/bit_manipulation.md) - Bitmask operations, GCC builtins
- [Graphs & Trees](notes/graphs_and_trees.md) - BFS, DFS, shortest paths, MST
- [Dynamic Programming](notes/dynamic_programming.md) - Knapsack, LIS, LCS, patterns
- [Greedy & Search](notes/greedy_and_search.md) - Exchange arguments, binary search

## Generated Statistics

### Repository Statistics

Exact repository statistics are generated automatically from the filesystem:

- **Total code files**: 403
- **Languages**: C++ (399), Python (2), Java (2)
- **Codeforces solutions**: 392
- **Templates**: 11

See [docs/generated/stats.md](docs/generated/stats.md) for complete breakdowns and [docs/generated/problem-index.md](docs/generated/problem-index.md) for the full problem index.

### External Platform Statistics

Public profile statistics from external competitive programming platforms:

- **Codeforces**: 374 solved, rating 815 (newbie) [via official API]
- **CodeChef**: rating 922, global rank 17165 [via browser rendering]
- **HackerRank**: 22 badges, 20 certifications [via public profile]
- **LeetCode**: See profile for current statistics
- **HackerEarth**: See profile for current statistics
- **GeeksforGeeks**: See profile for current statistics

See [docs/generated/external-stats.md](docs/generated/external-stats.md) for complete external platform statistics with retrieved metrics, retrieval methods, and timestamps.

Note: External platform statistics represent actual progress on those platforms and are separate from the solution files stored in this repository.

## Automation

The repository includes:

- **Statistics generation** - `scripts/generate_stats.py` scans the repository and generates counts
- **C++ validation** - `scripts/validate_cpp.py` verifies compilation of all C++ files
- **CI workflow** - GitHub Actions validates compilation on push/PR

See [scripts/](scripts/) and [.github/workflows/](.github/workflows/) for details.

## Connect

- [GitHub](https://github.com/prathamkashyap)
- [LinkedIn](https://www.linkedin.com/in/prathamkashyap5)
- [Codeforces](https://codeforces.com/profile/prathamkashyap)
