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

<!-- START_EXTERNAL_STATS -->
### External Platform Statistics

Public profile statistics from external competitive programming platforms (verified from public APIs, GraphQL, and structured profiles):

| Platform | Profile | Status | Solves / Rating | Key Highlights |
| :--- | :--- | :---: | :--- | :--- |
| **[LeetCode](https://leetcode.com/u/prathamkashyap/)** | `@prathamkashyap` | 📸 `snapshot` | **522** solved (171 E / 279 M / 72 H) | 87.8% AC |
| **[Codeforces](https://codeforces.com/profile/prathamkashyap)** | `@prathamkashyap` | 🟢 `live` | Rating **815** (`newbie`), **376** solved | Max rating 815, Official API verified |
| **[CodeChef](https://www.codechef.com/users/prathamkashyap)** | `@prathamkashyap` | 🟢 `live` | Rating **922** (★ 1 Star), **631** solved | Diamond League, DSA Monday **1067** (Rank #2,341) |
| **[HackerRank](https://www.hackerrank.com/profile/prathamkashyap)** | `@prathamkashyap` | 🟢 `live` | **26** stars, **356** solved | Problem Solving 6★ (#1,871), SQL 5★ (#1), C++ 5★/Java 5★/Python 5★ |
| **[HackerEarth](https://www.hackerearth.com/@prathamkashyap/)** | `@prathamkashyap` | 🟢 `live` | **4,370** pts, **178** solved (217 subs) | 14 badges |
| **[GeeksforGeeks](https://www.geeksforgeeks.org/profile/prathamkashyap)** | `@prathamkashyap` | 📸 `snapshot` | Score **424**, **98** solved | 28 POTDs solved, 28d streak, 96 subs (2026) |

<details>
<summary><b>Detailed Platform Breakdown & Honors</b></summary>

#### LeetCode ([@prathamkashyap](https://leetcode.com/u/prathamkashyap/))
- **Problem Solves**: `522` total (🟢 Easy: `171`, 🟡 Medium: `279`, 🔴 Hard: `72`)
- **Submissions & Acceptance**: `858` submissions, `—` accepted (`87.8%` AC rate)

#### Codeforces ([@prathamkashyap](https://codeforces.com/profile/prathamkashyap))
- **Current Rating**: `815` (`newbie`) | **Max Rating**: `815` (`newbie`)
- **Unique Solved Problems**: `376`

#### CodeChef ([@prathamkashyap](https://www.codechef.com/users/prathamkashyap))
- **Rating**: `922` (★ `1` Star) | **Max Rating**: `922` | **League**: `Diamond League`
- **DSA Monday Rating**: `1067` (Rank `#2,341`) | **Global Rank**: `#17,165`
- **Total Problems Solved**: `631`

#### HackerRank ([@prathamkashyap](https://www.hackerrank.com/profile/prathamkashyap))
- **Skill Badges**: Problem Solving (`6★`, `#1,871`), C++ (`5★`, `#65,859`), Java (`5★`, `#231,773`), Python (`5★`, `#351,747`), Sql (`5★`, `#1`)
- **Total Stars & Solves**: `26` stars earned, `356` challenges solved
- **Verified Skills**: `Algorithm`, `Javascript(Intermediate)`, `Data Structure`, `Python(Advanced)`, `React`, `Css`, `NodeJs`, `SQL`

#### HackerEarth ([@prathamkashyap](https://www.hackerearth.com/@prathamkashyap/))
- **Points & Solves**: `4,370` points, `178` solved, `217` solutions submitted
- **Badges**: Data Structures - 1 Star, Data Structures - 2 Stars, Algorithms - 1 Star, Algorithms - 2 Stars, Basic Programming - 1 Star, Basic Programming - 2 Stars, Basic Programming - 3 Stars, Basic Programming - 4 Stars, Basic Programming - 5 Stars, Novice, Amateur, Explorer, Elite, C++ language

#### GeeksforGeeks ([@prathamkashyap](https://www.geeksforgeeks.org/profile/prathamkashyap))
- **Coding Score**: `424` | **Total Solved**: `98`
- **Streaks & POTD**: `28` POTDs solved, `28` day longest streak
- **2026 Activity**: `96` submissions

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
