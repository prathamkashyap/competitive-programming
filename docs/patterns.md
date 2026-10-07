# Algorithmic Problem-Solving Patterns

This document provides a concise index of common algorithmic patterns for competitive programming and interview preparation.

## Pattern Recognition Guide

| Problem Shape | Consider This Technique |
|---------------|------------------------|
| Subarray with constraint | Sliding window, two pointers |
| Sorted search space | Binary search |
| Connectivity problem | DSU, DFS, BFS |
| Shortest path (unweighted) | BFS |
| Shortest path (weighted, non-negative) | Dijkstra |
| Repeated overlapping choices | Dynamic programming |
| Local optimality leads to global optimum | Greedy with proof |
| Range queries on static array | Prefix sums, sparse table |
| Range queries with updates | Segment tree, Fenwick tree |
| Prime-related computations | Sieve, modular arithmetic |
| Permutation/combination counting | DP, combinatorics |
| Tree path queries | LCA, DFS preprocessing |

## Core Patterns

### Arrays
**When to recognize:** Problems involving subarrays, prefix sums, or array transformations.

**Core idea:** Leverage index structure, preprocessing, or two-pointer techniques.

**Common complexity:** $O(N)$ to $O(N \log N)$

**Pitfalls:** Off-by-one errors, integer overflow, boundary conditions.

**Representative references:**
- [patterns/arrays.md](../patterns/arrays.md)
- [templates/cpp/prefix_sums.cpp](../templates/cpp/prefix_sums.cpp)

### Two Pointers
**When to recognize:** Sorted arrays, paired elements, or problems requiring simultaneous traversal from both ends.

**Core idea:** Maintain two indices that move toward each other or in the same direction to satisfy constraints.

**Common complexity:** $O(N)$ for sorted arrays

**Pitfalls:** Incorrect pointer movement logic, missing update conditions.

**Representative references:**
- [patterns/two-pointers.md](../patterns/two-pointers.md)

### Sliding Window
**When to recognize:** Subarray/substring constraints (fixed size, at-most-K, sum constraints).

**Core idea:** Maintain a window of elements that expands and contracts while tracking aggregate information.

**Common complexity:** $O(N)$ amortized

**Pitfalls:** Window update order, duplicate counting, invalid window states.

**Representative references:**
- [patterns/sliding-window.md](../patterns/sliding-window.md)
- [templates/cpp/sliding_window.cpp](../templates/cpp/sliding_window.cpp)

### Binary Search
**When to recognize:** Monotonic search space, optimization problems with predicate feasibility, finding thresholds.

**Core idea:** Repeatedly halve search space based on a feasibility predicate.

**Common complexity:** $O(\log N)$

**Pitfalls:** Off-by-one in loop condition, overflow in mid calculation, incorrect predicate monotonicity.

**Representative references:**
- [patterns/binary-search.md](../patterns/binary-search.md)
- [notes/greedy_and_search.md](../notes/greedy_and_search.md)
- [notes/pitfalls/binary-search-invariants.md](../notes/pitfalls/binary-search-invariants.md)

### Greedy
**When to recognize:** Problems where local optimal choices lead to global optimum, often with sorting or interval scheduling.

**Core idea:** Make the locally optimal choice at each step, typically proven by exchange argument.

**Common complexity:** $O(N \log N)$ after sorting

**Pitfalls:** Assuming greedy works without proof, incorrect sorting criteria.

**Representative references:**
- [patterns/greedy.md](../patterns/greedy.md)
- [notes/greedy_and_search.md](../notes/greedy_and_search.md)

### Dynamic Programming
**When to recognize:** Overlapping subproblems, optimal substructure, counting possibilities, optimization with choices.

**Core idea:** Solve subproblems once and memoize or tabulate results, building up to the final answer.

**Common complexity:** $O(N \times state)$ to $O(N^2)$ or higher

**Pitfalls:** Incorrect state definition, transition errors, memory limits, missing base cases.

**Representative references:**
- [patterns/dynamic-programming.md](../patterns/dynamic-programming.md)
- [notes/dynamic_programming.md](../notes/dynamic_programming.md)
- [notes/pitfalls/dp-state-definition.md](../notes/pitfalls/dp-state-definition.md)

### Graphs
**When to recognize:** Networks, connectivity, paths, trees, grid-based movement.

**Core idea:** Model relationships as vertices and edges, apply traversal or shortest-path algorithms.

**Common complexity:** $O(V + E)$ for BFS/DFS, $O((V+E)\log V)$ for Dijkstra

**Pitfalls:** Stack overflow on deep recursion, incorrect adjacency representation, missing edge cases.

**Representative references:**
- [patterns/graphs.md](../patterns/graphs.md)
- [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)
- [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)
- [templates/cpp/dsu.cpp](../templates/cpp/dsu.cpp)

### Trees
**When to recognize:** Hierarchical structures, parent-child relationships, tree properties.

**Core idea:** Leverage tree properties (single path between nodes, recursive structure), apply DFS/BFS.

**Common complexity:** $O(N)$ for single traversal

**Pitfalls:** Confusing tree depth with node count, incorrect parent tracking.

**Representative references:**
- [patterns/trees.md](../patterns/trees.md)
- [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)

### Hashing
**When to recognize:** Frequency counting, grouping, O(1) lookups, duplicate detection.

**Core idea:** Map keys to values using hash functions for fast average-case operations.

**Common complexity:** $O(1)$ average, $O(N)$ worst-case

**Pitfalls:** Hash collisions, unordered iteration, memory overhead.

### Recursion and Backtracking
**When to recognize:** Enumerating possibilities, exploring state spaces, permutation/combination generation.

**Core idea:** Recursively explore choices, backtrack when invalid, prune when possible.

**Common complexity:** Exponential in worst case, often pruned

**Pitfalls:** Stack overflow, missing backtracking step, exponential blowup without pruning.

**Representative references:**
- [patterns/recursion-backtracking.md](../patterns/recursion-backtracking.md)
- [notes/pitfalls/recursion-and-stack-depth.md](../notes/pitfalls/recursion-and-stack-depth.md)

## Advanced Patterns

### Segment Trees
**When to recognize:** Range queries with point updates, dynamic range information.

**Core idea:** Binary tree representation of array ranges, combine child information for parent.

**Common complexity:** $O(\log N)$ per query/update

**Pitfalls:** Lazy propagation complexity, incorrect combine function.

**Representative references:**
- [templates/cpp/segment_tree.cpp](../templates/cpp/segment_tree.cpp)

### Fenwick Trees
**When to recognize:** Prefix sum queries with point updates, difference arrays for range updates.

**Core idea:** Binary indexed tree for efficient prefix sums and updates.

**Common complexity:** $O(\log N)$ per operation

**Pitfalls:** 1-indexed vs 0-indexed confusion, query direction.

**Representative references:**
- [templates/cpp/fenwick_tree.cpp](../templates/cpp/fenwick_tree.cpp)

### Number Theory
**When to recognize:** Primes, divisibility, modular arithmetic, combinatorics.

**Core idea:** Mathematical properties, precomputation (sieve), modular operations.

**Common complexity:** $O(N)$ for sieve, $O(\log N)$ for modular exponentiation

**Pitfalls:** Modulo on negative numbers, overflow in intermediate calculations.

**Representative references:**
- [notes/number_theory.md](../notes/number_theory.md)
- [templates/cpp/sieve_prime.cpp](../templates/cpp/sieve_prime.cpp)
- [templates/cpp/modular_arithmetic.cpp](../templates/cpp/modular_arithmetic.md)

## Pattern Selection Workflow

1. **Identify the data structure**: Array, tree, graph, string, number?
2. **Identify the operation**: Query, update, transformation, optimization?
3. **Check for constraints**: Sorted? Monotonic? Connectivity?
4. **Select pattern**: Match problem shape to pattern from the table above.
5. **Verify complexity**: Ensure solution fits time/memory limits.
6. **Check pitfalls**: Review common mistakes for the selected pattern.

## Further Reading

- [docs/roadmap.md](roadmap.md) - Progressive learning path
- [notes/](../notes/) - Detailed theoretical references
- [patterns/](../patterns/) - In-depth pattern documentation
