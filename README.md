<div align="center">

# 🚀 Competitive Programming & Algorithmic Problem Solving

[![GitHub repo size](https://img.shields.io/github/repo-size/prathamkashyap/competitive-programming?style=for-the-badge&logo=github&color=blue)](https://github.com/prathamkashyap/competitive-programming)
[![GitHub last commit](https://img.shields.io/github/last-commit/prathamkashyap/competitive-programming?style=for-the-badge&logo=git&color=green)](https://github.com/prathamkashyap/competitive-programming/commits/main)
[![Language: C++](https://img.shields.io/badge/Language-C++20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://github.com/prathamkashyap/competitive-programming)
[![Language: Python](https://img.shields.io/badge/Language-Python%203-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://github.com/prathamkashyap/competitive-programming)
[![Language: Java](https://img.shields.io/badge/Language-Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)](https://github.com/prathamkashyap/competitive-programming)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

<p align="center">
  <b>A curated, structured collection of 250+ competitive programming solutions, algorithmic blueprints, reusable C++/Python/Java templates, and foundational theory notes.</b>
</p>

[Codeforces](codeforces/) • [LeetCode](leetcode/) • [CSES](cses/) • [AtCoder](atcoder/) • [CodeChef](codechef/) • [HackerEarth](hackerearth/) • [Templates](templates/) • [Notes](notes/)

</div>

---

## 📌 Table of Contents

- [✨ Overview](#-overview)
- [📂 Repository Structure](#-repository-structure)
- [📊 Platforms & Problem Tracker](#-platforms--problem-tracker)
- [⚡ Quick Start & Development Setup](#-quick-start--development-setup)
- [🧠 Topics & Algorithmic Patterns](#-topics--algorithmic-patterns)
- [🛠️ CP Templates](#️-cp-templates)
- [📖 Theory & Cheat Sheets](#-theory--cheat-sheets)
- [🤝 Contributing & License](#-contributing--license)

---

## ✨ Overview

This repository documents my competitive programming journey and serves as an algorithmic reference library. It includes:

- 🎯 **Platform Solutions**: Systematically organized solutions from Codeforces, LeetCode, CSES Problem Set, AtCoder, CodeChef, and HackerEarth.
- 🧱 **Reusable Templates**: Modular implementations of common data structures and algorithms (DSU, Segment Trees, Fenwick Trees, Sieve, Fast I/O).
- 📝 **Concise Notes**: Quick-revision cheat sheets covering time complexity, number theory, bit manipulation, graphs, and dynamic programming.
- ⚡ **Optimized Code**: Clean, well-structured, fast C++ solutions adhering to modern CP standards (Fast I/O, 64-bit integer safety, standard macro definitions).

---

## 📂 Repository Structure

```tree
competitive-programming/
├── codeforces/          # Solutions categorized by difficulty rating (800 - 2000+)
│   ├── 800/             # Fundamental implementation & greedy problems
│   ├── 900/             # Basic math, string manipulation, brute force
│   ├── 1000/            # Constructive algorithms, sorting, two pointers
│   ├── 1100/            # Number theory, prefix sums, binary search
│   ├── 1200/            # DP basics, greedy, combinatorics
│   ├── 1300/            # Graph basics, modulo arithmetic, bitmasks
│   ├── 1400/            # Medium DP, tree traversals, two pointers
│   ├── 1500/            # Graphs (BFS/DFS), data structures, constructive
│   ├── 1600/            # Advanced greedy, dynamic programming
│   ├── 1700/            # Range queries, graph algorithms
│   ├── 1800/            # Advanced data structures, game theory
│   ├── 2000/            # Complex DP, segment trees, mathematical proofs
│   └── unrated_questions/# Contest problems & post-contest virtual submissions
├── leetcode/            # LeetCode solutions categorized by topic & difficulty
├── cses/                # Solutions to the CSES Problem Set
├── atcoder/             # Solutions to AtCoder Beginner & Regular Contests
├── codechef/            # Solutions to CodeChef Starters & Cook-Offs
├── hackerearth/         # Solutions to HackerEarth practice tracks & circuits
├── templates/           # Production-ready CP boilerplate & data structure templates
│   ├── cpp/             # C++ Fast I/O, DSU, Segment Tree, Sieve, Fenwick Tree
│   ├── python/          # Python fast I/O & math utility templates
│   └── java/            # Java FastScanner & FastWriter templates
└── notes/               # Curated algorithmic notes, cheat sheets & complexity tables
```

---

## 📊 Platforms & Problem Tracker

| Platform | Directory | Solved / Status | Primary Focus |
| :--- | :--- | :---: | :--- |
| **Codeforces** | [`/codeforces`](codeforces/) | **250+ Solved** | Div. 2 / Div. 3 Contests, Ratings 800 - 2000+ |
| **LeetCode** | [`/leetcode`](leetcode/) | In Progress | Data Structures, Algorithms & Interview Patterns |
| **CSES** | [`/cses`](cses/) | In Progress | Standard Algorithmic Problem Set & Intuition |
| **AtCoder** | [`/atcoder`](atcoder/) | In Progress | AtCoder Beginner Contest (ABC) & Math-Heavy Tasks |
| **CodeChef** | [`/codechef`](codechef/) | In Progress | Starters & Division-based Contests |
| **HackerEarth** | [`/hackerearth`](hackerearth/) | In Progress | Practice Tracks & Data Structure Challenges |

### 📈 Codeforces Difficulty Breakdown

```
 800  [████████████████████████████████████████] 83 problems
 900  [██████████████████] 37 problems
1000  [████████████████] 32 problems
1100  [██████████] 19 problems
1200  [███████████████] 31 problems
1300  [███████████████] 30 problems
1400  [███] 5 problems
1500  [████] 7 problems
1700+ [██] 3 problems
Contest/Unrated [███████████████] 30 problems
```

---

## ⚡ Quick Start & Development Setup

### Compilation Flags (C++20 Recommended)

For local compilation with strict warnings, memory safety, and optimization:

```bash
g++ -std=c++20 -O2 -Wall -Wextra -Wshadow -DLOCAL solution.cpp -o solution
./solution < input.txt
```

### VS Code & Competitive Companion Setup

1. Install the **Competitive Programming Helper (cph)** extension in VS Code.
2. Install **Competitive Companion** in your browser (Chrome/Firefox).
3. Clicking the green parsing button on any problem page will automatically generate test cases in VS Code.

---

## 🧠 Topics & Algorithmic Patterns

<details>
<summary><b>🔍 1. Data Structures</b></summary>

- Vectors, Pairs, Tuples, Deques
- Stacks, Queues, Monotonic Queue/Stack
- Sets, Multisets, Unordered Sets (Custom Hash)
- Priority Queues & Heaps
- Disjoint Set Union (DSU) with Path Compression & Union by Rank/Size
- Fenwick Trees (Binary Indexed Trees)
- Segment Trees (Point Updates, Range Queries, Lazy Propagation)
</details>

<details>
<summary><b>🔢 2. Mathematics & Number Theory</b></summary>

- Euclidean Algorithm & Extended Euclidean Algorithm (GCD / LCM)
- Modular Arithmetic & Modular Inverse ($O(\log M)$ using Fermat's Little Theorem)
- Sieve of Eratosthenes & Linear Sieve for Prime Factorization ($O(N)$)
- Binary Exponentiation ($O(\log N)$)
- Combinatorics ($nCr \pmod p$ with precomputed factorials)
- Matrix Exponentiation
- Inclusion-Exclusion Principle
</details>

<details>
<summary><b>🎯 3. Dynamic Programming</b></summary>

- 1D DP (Fibonacci, Frog Jump, House Robber)
- 2D & Grid DP (Unique Paths, Min Cost Path, Knapsack 0/1 & Unbounded)
- Longest Increasing Subsequence (LIS) in $O(N \log N)$
- Longest Common Subsequence (LCS) & Edit Distance
- Bitmask DP (Traveling Salesperson Problem, Assignment Problems)
- Tree DP & Subtree Aggregations
</details>

<details>
<summary><b>🌐 4. Graph Theory & Trees</b></summary>

- Graph Representations (Adjacency Lists, Edge Lists)
- Breadth-First Search (BFS) - Shortest Path in Unweighted Graphs
- Depth-First Search (DFS) - Connected Components, Cycle Detection
- Dijkstra's Algorithm - Shortest Path in Weighted Graphs with Non-Negative Weights ($O((V+E)\log V)$)
- Bellman-Ford & Floyd-Warshall Algorithms
- Minimum Spanning Tree (Kruskal with DSU, Prim's)
- Tree Traversals, Diameter, Center, and Lowest Common Ancestor (LCA with Binary Lifting)
- Topological Sorting (Kahn's Algorithm & DFS)
</details>

<details>
<summary><b>⚡ 5. General Paradigms & Techniques</b></summary>

- Two Pointers & Sliding Window
- Binary Search (on Answer / Monotonic Predicates)
- Ternary Search (Unimodal Functions)
- Greedy Algorithms & Exchange Arguments
- Prefix Sums, Difference Arrays & 2D Prefix Sums
- Coordinate Compression
- Bit Manipulation & Bitwise Operations
</details>

---

## 🛠️ CP Templates

Production-ready, battle-tested templates located in [`/templates`](templates/):

| Template | Language | Description | Link |
| :--- | :--- | :--- | :--- |
| **Fast I/O & CP Template** | C++ | Base boilerplate with fast I/O, typedefs, macros, and debug tools | [`template.cpp`](templates/cpp/template.cpp) |
| **Disjoint Set Union (DSU)** | C++ | Disjoint Set Union with rank/size optimization and path compression | [`dsu.cpp`](templates/cpp/dsu.cpp) |
| **Segment Tree** | C++ | Point update and range sum/min/max query tree | [`segment_tree.cpp`](templates/cpp/segment_tree.cpp) |
| **Fenwick Tree (BIT)** | C++ | 1D prefix sum and point update data structure | [`fenwick_tree.cpp`](templates/cpp/fenwick_tree.cpp) |
| **Sieve & Prime Utilities** | C++ | Sieve of Eratosthenes, SPF (Smallest Prime Factor), prime factor decomposition | [`sieve_prime.cpp`](templates/cpp/sieve_prime.cpp) |
| **Python CP Template** | Python | High-performance Python template with fast I/O and recursion limit boost | [`template.py`](templates/python/template.py) |
| **Java CP Template** | Java | FastScanner and FastWriter boilerplate for competitive programming in Java | [`Template.java`](templates/java/Template.java) |

---

## 📖 Theory & Cheat Sheets

Explore quick revision guides in [`/notes`](notes/):

- ⏱️ [**Time Complexity & Resource Limits**](notes/complexity_and_limits.md) - Constant factors, memory limits, and operation counters.
- 🔢 [**Number Theory & Modular Arithmetic**](notes/number_theory.md) - Prime generation, modular inverse, and combinatorial formulas.
- 💻 [**Bit Manipulation Hacks**](notes/bit_manipulation.md) - Bitmask operations, subset generation, and GCC builtins (`__builtin_popcount`, `__builtin_clz`).
- 🌲 [**Graph Theory & Tree Algorithms**](notes/graphs_and_trees.md) - Graph traversal templates, shortest path algorithms, and DSU.
- 💡 [**Dynamic Programming Patterns**](notes/dynamic_programming.md) - Classical DP states, transitions, and space-optimization tricks.

---

## 🤝 Contributing & License

Feel free to fork this repository, submit issues for alternative solutions or optimizations, or open pull requests with cleaner implementations.

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

<div align="center">
  <sub>Built with 💻 and ☕ by <a href="https://github.com/prathamkashyap">Pratham Kashyap</a>. Happy Coding!</sub>
</div>
