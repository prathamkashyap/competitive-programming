# 📝 Notes & Cheat Sheets

My personal collection of algorithmic theory and cheat sheets that I use for contest revision. These notes are language-agnostic and complement the solutions in this repository.

---

## 📚 Table of Contents

### Core Theory

|| Topic | Description | Key Topics ||
|| :--- | :--- | :--- ||
|| [⏱️ Complexity & Limits](complexity_and_limits.md) | Time & space complexity, hardware constants, data type limits | Ops per second ($10^8$), int vs long long vs \_\_int128, memory limits ||
|| [🔢 Number Theory](number_theory.md) | Primes, modular arithmetic, GCD/LCM, combinatorics | Sieve of Eratosthenes, Fermat's Little Theorem, $nCr \pmod p$, Modular Inverse ||
|| [💻 Bit Manipulation](bit_manipulation.md) | Bitwise operations, subsets, bitmasks, GCC built-ins | `__builtin_popcount`, `__builtin_clz`, iterating submasks, XOR properties ||
|| [🌲 Graphs & Trees](graphs_and_trees.md) | Graph traversals, shortest paths, spanning trees | BFS, DFS, Dijkstra, Bellman-Ford, Floyd-Warshall, Kruskal ||
|| [🌲 Trees Advanced](trees_advanced.md) | Tree queries, LCA, binary lifting | LCA with binary lifting, subtree queries, Euler tour ||
|| [💡 Dynamic Programming](dynamic_programming.md) | DP states, transitions, optimizations, patterns | 0/1 Knapsack, LIS ($O(N \log N)$), LCS, Grid DP, Bitmask DP, Space Optimization ||
|| [🎯 Greedy & Binary Search](greedy_and_search.md) | Proof patterns and monotonic search | Exchange arguments, interval scheduling, two pointers, answer-space search ||
|| [� Strings](strings.md) | String algorithms and hashing | KMP, Z-algorithm, rolling hash, suffix arrays ||
|| [🧮 Combinatorics](combinatorics.md) | Counting formulas and modular counting | nCr, Catalan numbers, stars-and-bars, inclusion-exclusion ||

### Cheat Sheets

|| Topic | Description ||
|| :--- | :--- ||
|| [⚡ Complexity Cheatsheet](cheatsheets/complexity_cheatsheet.md) | Quick reference for complexity analysis and TL heuristics ||
|| [🧩 STL Cheatsheet](cheatsheets/stl_cheatsheet.md) | Useful STL containers and algorithms for CP ||
|| [🔧 Implementation Tricks](cheatsheets/implementation_tricks.md) | Off-by-one, overflow, coordinate compression, and common gotchas ||

### Pitfalls

|| Topic | Description ||
|| :--- | :--- ||
|| [⚠️ Common Pitfalls](pitfalls/) | Practical mistakes that cost contests - off-by-one, overflow, recursion depth, etc. ||

---

## How I Use These Notes

I keep these notes for contest revision:
- **Pre-contest**: Scan relevant cheat sheets for data structures and complexity
- **Post-contest**: Add to pitfalls when I learn from mistakes
- **Practice**: Reference theory when stuck on a problem pattern

---

[← Back to Main Repository](../README.md)
