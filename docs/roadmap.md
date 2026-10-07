# DSA Learning Roadmap

This roadmap structures algorithmic topics progressively, with links to relevant templates, notes, and representative solutions from this repository.

## Foundations

### Arrays and Strings
- Array manipulation and traversal
- String processing and operations
- See [notes/complexity_and_limits.md](../notes/complexity_and_limits.md) for complexity fundamentals

### Hashing
- Hash maps and sets
- Collision handling
- Frequency counting

### Sorting
- Built-in sort functions
- Custom comparators
- Stability considerations

## Core Patterns

### Two Pointers
- Opposite-direction pointers
- Same-direction pointers
- See [patterns/two-pointers.md](../patterns/two-pointers.md)

### Sliding Window
- Fixed-size windows
- Variable-size windows
- At-most-K constraints
- Template: [templates/cpp/sliding_window.cpp](../templates/cpp/sliding_window.cpp)

### Binary Search
- Standard binary search on sorted arrays
- Binary search on answer (monotonic predicates)
- See [patterns/binary-search.md](../patterns/binary-search.md)
- Note: [notes/greedy_and_search.md](../notes/greedy_and_search.md)
- Representative: [codeforces/1200/1613C_PoisonedDagger.cpp](../codeforces/1200/1613C_PoisonedDagger.cpp)

### Greedy
- Exchange arguments
- Interval scheduling
- Sorting strategies
- See [patterns/greedy.md](../patterns/greedy.md)
- Note: [notes/greedy_and_search.md](../notes/greedy_and_search.md)

### Recursion and Backtracking
- Recursive problem decomposition
- State space exploration
- Pruning strategies
- See [patterns/recursion-backtracking.md](../patterns/recursion-backtracking.md)

## Data Structures

### Stacks and Queues
- LIFO and FIFO operations
- Monotonic stacks
- Queue applications

### Linked Lists
- Singly and doubly linked lists
- Pointer manipulation
- Cycle detection

### Trees
- Binary trees
- Tree traversals (inorder, preorder, postorder)
- See [patterns/trees.md](../patterns/trees.md)

### Heaps
- Priority queues
- Min-heap and max-heap
- Heap operations

### Tries
- Prefix trees
- String search applications

### Disjoint Set Union (DSU)
- Union-find with path compression
- Union by size/rank
- Template: [templates/cpp/dsu.cpp](../templates/cpp/dsu.cpp)

## Graphs

### Graph Traversal
- BFS for shortest paths in unweighted graphs
- DFS for connectivity and cycle detection
- See [patterns/graphs.md](../patterns/graphs.md)
- Note: [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)
- Template: [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)

### Topological Sorting
- DAG traversal
- Kahn's algorithm
- Template: [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)

### Shortest Paths
- Dijkstra's algorithm for weighted graphs
- Bellman-Ford for negative edges
- Floyd-Warshall for all-pairs shortest paths
- Note: [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)
- Template: [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)

### Minimum Spanning Tree
- Kruskal's algorithm with DSU
- Prim's algorithm
- Note: [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)

### Advanced Graph Algorithms
- Lowest Common Ancestor (LCA)
- Strongly connected components
- Articulation points and bridges

## Dynamic Programming

### DP Fundamentals
- State definition
- Transition formulation
- Base cases
- See [patterns/dynamic-programming.md](../patterns/dynamic-programming.md)
- Note: [notes/dynamic_programming.md](../notes/dynamic_programming.md)

### Classic DP Patterns
- 0/1 Knapsack
- Longest Increasing Subsequence (LIS)
- Longest Common Subsequence (LCS)
- Grid DP
- Note: [notes/dynamic_programming.md](../notes/dynamic_programming.md)

### DP Optimizations
- Space optimization
- Monotonic queue optimization
- Divide and conquer optimization

## Advanced Data Structures

### Segment Trees
- Point updates and range queries
- Lazy propagation
- Template: [templates/cpp/segment_tree.cpp](../templates/cpp/segment_tree.cpp)

### Fenwick Trees (Binary Indexed Trees)
- Prefix sum queries and point updates
- Range updates with difference arrays
- Template: [templates/cpp/fenwick_tree.cpp](../templates/cpp/fenwick_tree.cpp)

### Sparse Tables
- Range minimum queries (RMQ)
- Static array preprocessing

## Number Theory

### Primes and Factorization
- Sieve of Eratosthenes
- Prime factorization
- See [notes/number_theory.md](../notes/number_theory.md)
- Template: [templates/cpp/sieve_prime.cpp](../templates/cpp/sieve_prime.cpp)

### Modular Arithmetic
- Modular exponentiation
- Modular inverse
- Fermat's Little Theorem
- See [notes/number_theory.md](../notes/number_theory.md)
- Template: [templates/cpp/modular_arithmetic.cpp](../templates/cpp/modular_arithmetic.cpp)

### Combinatorics
- Permutations and combinations
- nCr modulo prime
- Template: [templates/cpp/modular_arithmetic.cpp](../templates/cpp/modular_arithmetic.cpp)

## Competitive Programming Techniques

### Prefix Sums
- Range sum queries
- Difference arrays for range updates
- Template: [templates/cpp/prefix_sums.cpp](../templates/cpp/prefix_sums.cpp)

### Bit Manipulation
- Bitmask operations
- Subset generation
- GCC builtins
- See [notes/bit_manipulation.md](../notes/bit_manipulation.md)

### Complexity Analysis
- Time complexity estimation
- Space complexity considerations
- See [notes/complexity_and_limits.md](../notes/complexity_and_limits.md)
- See [notes/pitfalls/complexity-mistakes.md](../notes/pitfalls/complexity-mistakes.md)

## Practice Progression

This repository contains solutions organized by difficulty in the [codeforces/](../codeforces/) directory:

- **800-900**: Fundamental implementation and greedy problems
- **1000-1100**: Basic data structures and simple algorithms
- **1200-1300**: Intermediate patterns (DP, graphs, number theory)
- **1400+**: Advanced techniques and problem-solving strategies

See [docs/generated/stats.md](generated/stats.md) for current solution counts by difficulty rating.
