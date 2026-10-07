# Interview DSA Roadmap

An interview-oriented progression based on the repository's existing material.

## Phase 1: Foundations

### Arrays and Strings
- Array manipulation and traversal
- String processing
- Prefix sums for range queries
- **Template**: [templates/cpp/prefix_sums.cpp](../templates/cpp/prefix_sums.cpp)
- **Pattern**: [patterns/arrays.md](../patterns/arrays.md)

### Hashing
- Hash maps for frequency counting
- O(1) lookups and membership tests
- **Pattern**: [patterns/hashing.md](../patterns/hashing.md)

### Sorting
- Built-in sort functions
- Custom comparators
- Sorting-based greedy approaches

## Phase 2: Core Patterns

### Two Pointers
- Opposite-direction pointers on sorted arrays
- Same-direction pointers for paired elements
- **Pattern**: [patterns/two-pointers.md](../patterns/two-pointers.md)

### Sliding Window
- Fixed-size windows for subarray problems
- Variable-size windows with constraints
- **Template**: [templates/cpp/sliding_window.cpp](../templates/cpp/sliding_window.cpp)
- **Pattern**: [patterns/sliding-window.md](../patterns/sliding-window.md)

### Binary Search
- Standard binary search on sorted arrays
- Binary search on answer (monotonic predicates)
- **Pattern**: [patterns/binary-search.md](../patterns/binary-search.md)
- **Note**: [notes/pitfalls/binary-search-invariants.md](../notes/pitfalls/binary-search-invariants.md)

### Greedy
- Exchange arguments for proof
- Interval scheduling problems
- Sorting-based selection
- **Pattern**: [patterns/greedy.md](../patterns/greedy.md)

## Phase 3: Data Structures

### Stacks and Queues
- LIFO and FIFO operations
- Monotonic stacks for next greater element
- Queue applications (BFS)

### Linked Lists
- Singly and doubly linked lists
- Pointer manipulation
- Cycle detection (Floyd's algorithm)

### Trees
- Binary tree traversals (inorder, preorder, postorder)
- Tree properties (height, diameter)
- **Pattern**: [patterns/trees.md](../patterns/trees.md)
- **Note**: [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)

### Heaps
- Priority queues (min-heap, max-heap)
- Heap operations (insert, extract-min)
- Applications (top K elements)

### Disjoint Set Union (DSU)
- Union-find with path compression
- Union by size/rank
- **Template**: [templates/cpp/dsu.cpp](../templates/cpp/dsu.cpp)

## Phase 4: Graphs

### Graph Traversal
- BFS for shortest paths in unweighted graphs
- DFS for connectivity and cycle detection
- **Pattern**: [patterns/graphs.md](../patterns/graphs.md)
- **Template**: [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)
- **Note**: [notes/pitfalls/graph-traversal-mistakes.md](../notes/pitfalls/graph-traversal-mistakes.md)

### Topological Sorting
- DAG traversal and ordering
- Kahn's algorithm
- **Template**: [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)

### Shortest Paths
- Dijkstra's algorithm for weighted graphs
- BFS for unweighted graphs
- **Template**: [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)
- **Note**: [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)

### Minimum Spanning Tree
- Kruskal's algorithm with DSU
- **Note**: [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)

## Phase 5: Dynamic Programming

### DP Fundamentals
- State definition and transition
- Base cases
- Memoization vs tabulation
- **Pattern**: [patterns/dynamic-programming.md](../patterns/dynamic-programming.md)
- **Note**: [notes/dynamic_programming.md](../notes/dynamic_programming.md)
- **Note**: [notes/pitfalls/dp-state-definition.md](../notes/pitfalls/dp-state-definition.md)

### Classic DP Patterns
- 0/1 Knapsack
- Longest Increasing Subsequence (LIS)
- Longest Common Subsequence (LCS)
- Grid DP
- **Note**: [notes/dynamic_programming.md](../notes/dynamic_programming.md)

### DP Optimizations
- Space optimization (1D arrays)
- Monotonic queue optimization
- **Pattern**: [patterns/dynamic-programming.md](../patterns/dynamic-programming.md)

## Phase 6: Advanced Topics

### Advanced Data Structures
- Segment trees for range queries
- Fenwick trees for prefix sums with updates
- **Template**: [templates/cpp/segment_tree.cpp](../templates/cpp/segment_tree.cpp)
- **Template**: [templates/cpp/fenwick_tree.cpp](../templates/cpp/fenwick_tree.cpp)

### Number Theory
- Primes and sieve
- Modular arithmetic
- Combinatorics (nCr modulo prime)
- **Note**: [notes/number_theory.md](../notes/number_theory.md)
- **Template**: [templates/cpp/sieve_prime.cpp](../templates/cpp/sieve_prime.cpp)
- **Template**: [templates/cpp/modular_arithmetic.cpp](../templates/cpp/modular_arithmetic.cpp)

### Bit Manipulation
- Bitmask operations
- Subset generation
- **Note**: [notes/bit_manipulation.md](../notes/bit_manipulation.md)

## Complexity Analysis

Interviewers often ask about complexity. Be prepared to discuss:
- Time complexity estimation
- Space complexity
- Trade-offs between approaches
- **Reference**: [notes/complexity_and_limits.md](../notes/complexity_and_limits.md)
- **Reference**: [notes/pitfalls/complexity-mistakes.md](../notes/pitfalls/complexity-mistakes.md)

## Practice Progression

The main repository contains solutions organized by difficulty:
- **800-900**: Foundation (arrays, basic logic)
- **1000-1100**: Data structures (hash maps, sorting)
- **1200-1300**: Intermediate (DP, graphs, number theory)
- **1400+**: Advanced techniques

See [docs/generated/stats.md](../docs/generated/stats.md) for current counts.

## Interview Tips

1. **Clarify the problem**: Ask questions before coding
2. **Think aloud**: Explain your approach
3. **Start with brute force**: Then optimize
4. **Test edge cases**: Empty input, single element, boundaries
5. **Discuss complexity**: Time and space for your solution
6. **Handle errors**: Check for nulls, bounds, invalid input

## Further Reading

- [patterns/](../patterns/) - In-depth pattern documentation
- [notes/](../notes/) - Theoretical reference material
- [curated-problems.md](curated-problems.md) - Representative problem set
