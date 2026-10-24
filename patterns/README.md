# 🧩 Algorithmic Patterns 💡

My documentation on common algorithmic problem-solving patterns for competitive programming and interview preparation.

Each pattern document explains:
- ✅ When to recognize the pattern
- 🧠 Core idea and invariant
- ⏱️ Common complexity
- 🔄 Common variations
- ⚠️ Common pitfalls
- 🎮 Representative problems from this repository

---

## 📚 Available Patterns

| 🎯 Pattern | 📖 Description | 💡 Key Topics |
| :--- | :--- | :--- |
| [Arrays](arrays.md) | Prefix sums, two pointers, array transformations | Range queries, sliding window, frequency counting |
| [Two Pointers](two-pointers.md) | Opposite and same-direction pointer techniques | Slow-fast pointers, meeting pointers, window expansion |
| [Sliding Window](sliding-window.md) | Fixed and variable-size windows | At-most-K, bounded sums, frequency counting |
| [Binary Search](binary-search.md) | Standard search and binary search on answer | Monotonic predicates, answer-space search |
| [Greedy](greedy.md) | Exchange arguments, interval scheduling | Sorting by criteria, local optimality |
| [Recursion and Backtracking](recursion-backtracking.md) | State space exploration | Permutations, combinations, pruning |
| [Trees](trees.md) | Tree traversal, diameter, LCA | DFS, BFS, subtree queries |
| [Graphs](graphs.md) | BFS, DFS, shortest paths, MST | Connectivity, components, flows |
| [Dynamic Programming](dynamic-programming.md) | State design, transitions, optimization | Memoization, tabulation, space optimization |
| [Hashing](hashing.md) | Frequency counting, lookups, rolling hash | Hash maps, hash sets, collision handling |

---

## 🎯 How to Use

### 1️⃣ Problem Identification
Match problem shape to pattern by reading constraints and asking:
- Is the answer monotonic? → Binary search
- Can I maintain a window? → Sliding window
- Is there optimal substructure? → DP
- Can I sort to simplify? → Greedy

### 2️⃣ Pattern Reference
Read the pattern document for core idea and implementation details

### 3️⃣ Template Usage
Copy templates from [templates/](../templates/) for data structures

### 4️⃣ Pitfall Avoidance
Review [notes/pitfalls/](../notes/pitfalls/) for common mistakes

---

## 🧠 Quick Reference

| 🎯 Problem Type | 🧩 Pattern | 🛠️ Template |
| :--- | :--- | :--- |
| Range sum queries | Prefix sums | [`prefix_sums.cpp`](../templates/cpp/prefix_sums.cpp) |
| At-most-K distinct | Sliding window | [`sliding_window.cpp`](../templates/cpp/sliding_window.cpp) |
| Find minimum in range | Sparse table | [`sparse_table.cpp`](../templates/cpp/sparse_table.cpp) |
| Tree ancestor queries | LCA | [`lca.cpp`](../templates/cpp/lca.cpp) |
| Pattern matching | KMP | [`kmp.cpp`](../templates/cpp/kmp.cpp) |

---

## 📖 Related

- [../docs/patterns.md](../docs/patterns.md) - Top-level pattern index
- [../docs/roadmap.md](../docs/roadmap.md) - Progressive learning path
- [../notes/](../notes/) - Theoretical reference material
- [../templates/](../templates/) - Implementation templates

---

[← Back to Main Repository](../README.md)
