# Competitive Programming & Algorithmic Problem Solving

A repository of algorithmic problem solutions, reusable templates, and algorithmic notes for competitive programming and interview preparation.

## What This Repository Contains

- **400+ Codeforces solutions** organized by difficulty rating (800-2000)
- **Reusable C++ templates** for common data structures and algorithms
- **Algorithmic notes** covering complexity, number theory, graphs, DP, and more
- **Multi-language support** with C++ as the primary language (Python and Java also available)

## Quick Navigation

- [Interactive Dashboard](docs/dashboard/index.html) - Live stats and searchable problem browser (GitHub Pages: https://prathamkashyap.github.io/competitive-programming/dashboard/)
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

<!-- START_EXTERNAL_STATS -->
### External Platform Statistics

Public profile statistics from external competitive programming platforms (verified from public APIs, GraphQL, and structured profiles):


![Codeforces Rating](docs/generated/badges/codeforces-rating.svg) 
![LeetCode Solved](docs/generated/badges/leetcode-solved.svg) 
![CodeChef Rating](docs/generated/badges/codechef-rating.svg) 
![Repo Solutions](docs/generated/badges/repo-solutions.svg)


| Platform | Profile | Status | Solves / Rating | Key Highlights |
| :--- | :--- | :---: | :--- | :--- |
| **[LeetCode](https://leetcode.com/u/prathamkashyap/)** | `@prathamkashyap` | 🟢 `live` | **542** solved (176 E / 290 M / 76 H) | 89.6% AC, #183,108, 118d streak, 10 badges |
| **[Codeforces](https://codeforces.com/profile/prathamkashyap)** | `@prathamkashyap` | 🟢 `live` | Rating **815** (`newbie`), **408** solved | Max rating 815, Official API verified |
| **[CodeChef](https://www.codechef.com/users/prathamkashyap)** | `@prathamkashyap` | 🟢 `live` | Rating **922** (★ 1 Star), **651** solved | Gold League, DSA Monday **1067** (Rank #2,341) |
| **[HackerRank](https://www.hackerrank.com/profile/prathamkashyap)** | `@prathamkashyap` | 🟢 `live` | **26** stars, **401** solved | Problem Solving 6★ (#1,295), SQL 5★ (#1), C++ 5★/Java 5★/Python 5★ |
| **[HackerEarth](https://www.hackerearth.com/@prathamkashyap/)** | `@prathamkashyap` | 🟢 `live` | **5,380** pts, **223** solved (265 subs) | 16 badges |
| **[GeeksforGeeks](https://www.geeksforgeeks.org/profile/prathamkashyap)** | `@prathamkashyap` | 🟢 `live` | Score **618**, **150** solved | 45 POTDs solved, 45d streak, 147 subs (2026) |

<details>
<summary><b>Detailed Platform Breakdown & Honors</b></summary>

#### LeetCode ([@prathamkashyap](https://leetcode.com/u/prathamkashyap/))
- **Problem Solves**: `542` total (🟢 Easy: `176`, 🟡 Medium: `290`, 🔴 Hard: `76`)
- **Submissions & Acceptance**: `1034` submissions, `926` accepted (`89.6%` AC rate)
- **Rankings & Streaks**: Global Rank `#183,108`, `118` days current streak, `122` total active days
- **Languages**: C++ (`521`), Java (`98`), Python3 (`98`), Pandas (`15`)
- **Featured Badges**: 100 Days Badge 2026, 50 Days Badge 2026, 100 Days Badge 2025, 50 Days Badge 2025, Sep LeetCoding Challenge, Aug LeetCoding Challenge

#### Codeforces ([@prathamkashyap](https://codeforces.com/profile/prathamkashyap))
- **Current Rating**: `815` (`newbie`) | **Max Rating**: `815` (`newbie`)
- **Unique Solved Problems**: `408`

#### CodeChef ([@prathamkashyap](https://www.codechef.com/users/prathamkashyap))
- **Rating**: `922` (★ `1` Star) | **Max Rating**: `922` | **League**: `Gold League`
- **DSA Monday Rating**: `1067` (Rank `#2,341`) | **Global Rank**: `#17,165`
- **Total Problems Solved**: `651`

#### HackerRank ([@prathamkashyap](https://www.hackerrank.com/profile/prathamkashyap))
- **Skill Badges**: Problem Solving (`6★`, `#1,295`), C++ (`5★`, `#65,982`), Java (`5★`, `#232,753`), Python (`5★`, `#352,943`), Sql (`5★`, `#1`)
- **Total Stars & Solves**: `26` stars earned, `401` challenges solved
- **Verified Skills**: `Algorithm`, `Javascript(Intermediate)`, `Data Structure`, `Python(Advanced)`, `React`, `Css`, `NodeJs`, `SQL`

#### HackerEarth ([@prathamkashyap](https://www.hackerearth.com/@prathamkashyap/))
- **Points & Solves**: `5,380` points, `223` solved, `265` solutions submitted
- **Badges**: Algorithms - 1 Star, Algorithms - 2 Stars, Algorithms - 3 Stars, Math - 1 Star, Data Structures - 1 Star, Data Structures - 2 Stars, Novice, Amateur, Explorer, Elite, C++ language, Basic Programming - 1 Star, Basic Programming - 2 Stars, Basic Programming - 3 Stars, Basic Programming - 4 Stars, Basic Programming - 5 Stars

#### GeeksforGeeks ([@prathamkashyap](https://www.geeksforgeeks.org/profile/prathamkashyap))
- **Coding Score**: `618` | **Total Solved**: `150` (Basic: `8`, Easy: `25`, Medium: `95`, Hard: `22`)
- **Streaks & POTD**: `45` POTDs solved, `45` day longest streak
- **2026 Activity**: `147` submissions across `45` active days

</details>

See [docs/generated/external-stats.md](docs/generated/external-stats.md) for complete external platform statistics with retrieved metrics, retrieval methods, and timestamps.

> [!NOTE]
> External platform statistics represent actual progress on external accounts and are tracked independently from the solution files stored in this repository. Solved counts are maintained separately and not combined into a misleading total.
<!-- END_EXTERNAL_STATS -->


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
