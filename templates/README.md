# 🛠️ Templates ⚡

My collection of reusable competitive programming snippets, data structures, and language boilerplate that I copy-paste into contests. Each template is syntax-checked in this repository.

---

## 📋 Available Templates

### 🔷 C++ Templates (`cpp/`)

| 🎯 Template File | 🧩 Data Structure / Algorithm | ⏱️ Time Complexity | 💾 Space Complexity | 📖 Description |
| :--- | :--- | :---: | :---: | :--- |
| [`template.cpp`](cpp/template.cpp) | **CP Boilerplate** | $O(1)$ | $O(1)$ | Fast I/O, `ll` aliases, pbds, modular exponentiation, GCD |
| [`dsu.cpp`](cpp/dsu.cpp) | **Disjoint Set Union** | $O(\alpha(N)) \approx O(1)$ | $O(N)$ | DSU with Path Compression & Union by Size/Rank |
| [`segment_tree.cpp`](cpp/segment_tree.cpp) | **Segment Tree** | $O(\log N)$ query / update | $O(4N)$ | Point update, range sum/min/max query engine |
| [`fenwick_tree.cpp`](cpp/fenwick_tree.cpp) | **Binary Indexed Tree** | $O(\log N)$ query / update | $O(N)$ | Compact 1D prefix sum & point update structure |
| [`sieve_prime.cpp`](cpp/sieve_prime.cpp) | **Linear Sieve & SPF** | $O(N)$ build, $O(\log K)$ factor | $O(N)$ | Sieve of Eratosthenes, Smallest Prime Factor array, fast prime factoring |
| [`modular_arithmetic.cpp`](cpp/modular_arithmetic.cpp) | **Modular Arithmetic** | $O(\log MOD)$ power / inverse | $O(N)$ for combinations | Fast power, Fermat inverse, factorials, and $nCr$ |
| [`graph_traversal.cpp`](cpp/graph_traversal.cpp) | **Graph Traversal Toolkit** | $O(V + E)$ BFS/topological sort; $O((V+E)\log V)$ Dijkstra | $O(V + E)$ | BFS distances, Kahn topological sort, and weighted shortest paths |
| [`prefix_sums.cpp`](cpp/prefix_sums.cpp) | **Prefix & Difference Arrays** | $O(1)$ query/update, $O(N)$ build | $O(N)$ | Range sums, range additions, and reconstruction |
| [`sliding_window.cpp`](cpp/sliding_window.cpp) | **Sliding Window Toolkit** | $O(N)$ amortized | $O(N)$ | At-most-$K$ distinct, bounded sums, and prefix-frequency counting |
| [`lca.cpp`](cpp/lca.cpp) | **LCA (Binary Lifting)** | $O(N \log N)$ preprocess, $O(\log N)$ query | $O(N \log N)$ | Lowest Common Ancestor with binary lifting |
| [`sparse_table.cpp`](cpp/sparse_table.cpp) | **Sparse Table (RMQ)** | $O(N \log N)$ preprocess, $O(1)$ query | $O(N \log N)$ | Range minimum/maximum query on static array |
| [`trie.cpp`](cpp/trie.cpp) | **Trie** | $O(L)$ insert/search | $O(\Sigma L)$ | Prefix tree for strings and pattern matching |
| [`string_hash.cpp`](cpp/string_hash.cpp) | **String Hashing** | $O(L)$ hash, $O(1)$ compare | $O(N)$ | Rolling hash for string comparison and pattern matching |
| [`kmp.cpp`](cpp/kmp.cpp) | **Knuth-Morris-Pratt** | $O(N + M)$ build/search | $O(M)$ | Pattern matching with prefix function |
| [`pbds_ordered_set.cpp`](cpp/pbds_ordered_set.cpp) | **Ordered Set (PBDS)** | $O(\log N)$ insert/erase/order statistics | $O(N)$ | Policy-based ordered_set with order_of_key and find_by_order |

### 🐍 Python Templates (`python/`)

| 🎯 Template File | 📖 Description | ✨ Features |
| :--- | :--- | :--- |
| [`template.py`](python/template.py) | **Python CP Boilerplate** | `sys.stdin.readline`, boosted recursion limit (`sys.setrecursionlimit`), modular arithmetic helpers |

### ☕ Java Templates (`java/`)

| 🎯 Template File | 📖 Description | ✨ Features |
| :--- | :--- | :--- |
| [`Template.java`](java/Template.java) | **Java CP Boilerplate** | Ultra-fast `BufferedReader` + `StringTokenizer` custom `FastScanner`, `PrintWriter` |

---

## ⚡ How to Use

Simply include or paste the necessary class/template into your solution file, or link them using standard `#include` in your local environment.

### 🎯 Quick Tips

- **Fast I/O**: Always use `ios_base::sync_with_stdio(false); cin.tie(nullptr);` for C++
- **Modular Arithmetic**: Precompute factorials and inverse factorials for multiple nCr queries
- **DSU**: Remember to call `find` on both elements before union to ensure correctness
- **Segment Tree**: Use 4n as safe array size for range queries
- **PBDS**: Useful for order statistics problems (k-th element, count less than x)

---

## 🧠 Template Selection Guide

### 🎮 For Graph Problems
- **Unweighted shortest path**: Use [`graph_traversal.cpp`](cpp/graph_traversal.cpp) for BFS
- **Weighted shortest path**: Use [`graph_traversal.cpp`](cpp/graph_traversal.cpp) for Dijkstra
- **Minimum spanning tree**: Add Kruskal with DSU from [`dsu.cpp`](cpp/dsu.cpp)

### 🔢 For Number Theory
- **Modular arithmetic**: Use [`modular_arithmetic.cpp`](cpp/modular_arithmetic.cpp) for nCr and modular inverse
- **Prime operations**: Use [`sieve_prime.cpp`](cpp/sieve_prime.cpp) for factorization and prime testing

### 📊 For Range Queries
- **Point updates + range queries**: Use [`segment_tree.cpp`](cpp/segment_tree.cpp) or [`fenwick_tree.cpp`](cpp/fenwick_tree.cpp)
- **Static array RMQ**: Use [`sparse_table.cpp`](cpp/sparse_table.cpp) for O(1) queries
- **Frequency counting**: Use [`sliding_window.cpp`](cpp/sliding_window.cpp) for at-most-K problems

### 🔗 For String Problems
- **Pattern matching**: Use [`kmp.cpp`](cpp/kmp.cpp) for single pattern search
- **String comparison**: Use [`string_hash.cpp`](cpp/string_hash.cpp) for rolling hash
- **Prefix operations**: Use [`trie.cpp`](cpp/trie.cpp) for dictionary and prefix matching

### 🌲 For Tree Problems
- **LCA queries**: Use [`lca.cpp`](cpp/lca.cpp) with binary lifting
- **Subtree queries**: Use Euler tour technique with prefix sums

---

[← Back to Main Repository](../README.md)
