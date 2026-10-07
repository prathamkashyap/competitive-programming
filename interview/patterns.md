# Interview Pattern Recognition

A compact guide for quick pattern recognition during interviews.

## Problem Shape → Technique

| Problem Shape | Consider This Technique |
|---------------|------------------------|
| **Subarray with constraint** | Sliding window, two pointers, prefix sums |
| **Sorted search space** | Binary search |
| **Find k-th smallest/largest** | Binary search, heap, quickselect |
| **Connectivity problem** | DSU, DFS, BFS |
| **Shortest path (unweighted)** | BFS |
| **Shortest path (weighted, non-negative)** | Dijkstra |
| **Shortest path (may have negative)** | Bellman-Ford |
| **Repeated overlapping choices** | Dynamic programming |
| **Local optimality → global optimum** | Greedy (with proof) |
| **Range queries on static array** | Prefix sums, sparse table |
| **Range queries with updates** | Segment tree, Fenwick tree |
| **Prime-related computations** | Sieve, modular arithmetic |
| **Permutation/combination counting** | DP, combinatorics |
| **Tree path queries** | LCA, DFS preprocessing |
| **String matching** | KMP, rolling hash, trie |
| **Pair sum problems** | Hash map, two pointers (if sorted) |
| **Interval scheduling** | Greedy (sort by end time) |
| **Maximum subarray** | Kadane's algorithm, prefix sums |
| **Longest increasing subsequence** | DP with binary search ($O(N \log N)$) |
| **Edit distance** | DP |

## Key Interview Patterns

### Arrays
- **Two sum**: Hash map for O(N) lookup
- **Maximum subarray**: Kadane's algorithm
- **Prefix sums**: Range sum queries in O(1)
- **Sliding window**: Subarray constraints

### Strings
- **Anagrams**: Hash map character counting
- **Longest substring without repeating**: Sliding window
- **Edit distance**: DP

### Binary Search
- **Search in sorted array**: Standard binary search
- **Find minimum/maximum satisfying condition**: Binary search on answer
- **Search in rotated sorted array**: Modified binary search

### Graphs
- **Shortest path unweighted**: BFS
- **Shortest path weighted**: Dijkstra
- **Connectivity**: DFS/BFS, DSU
- **Topological sort**: Kahn's algorithm

### Dynamic Programming
- **Knapsack**: DP[i][w] = max value with first i items, weight w
- **LIS**: DP[i] = LIS ending at i, or binary search for O(N log N)
- **LCS**: DP[i][j] = LCS of first i chars of s1, first j chars of s2
- **Grid DP**: DP[i][j] from neighbors

### Trees
- **Traversal**: DFS (recursive or iterative)
- **Lowest common ancestor**: Binary lifting
- **Diameter**: Two BFS passes

### Greedy
- **Interval scheduling**: Sort by end time
- **Activity selection**: Greedy by finish time
- **Huffman coding**: Greedy by frequency

## Common Interview Mistakes

1. **Not clarifying assumptions**: Ask about input constraints, edge cases
2. **Jumping to code**: Discuss approach first
3. **Ignoring complexity**: Always state time and space complexity
4. **Not testing**: Walk through examples
5. **Silent debugging**: Think aloud during debugging

## Complexity Quick Reference

| Data Structure | Operation | Complexity |
|---------------|----------|------------|
| Array | Access | O(1) |
| Array | Search | O(N) |
| Sorted Array | Binary Search | O(log N) |
| Hash Map | Insert/Lookup | O(1) average |
| Heap | Insert/Extract | O(log N) |
| BST | Insert/Search/Delete | O(log N) average |
| Stack/Queue | Push/Pop | O(1) |
| Linked List | Access | O(N) |
| Linked List | Insert/Delete at head | O(1) |

| Algorithm | Complexity |
|-----------|------------|
| Sorting | O(N log N) |
| BFS/DFS | O(V + E) |
| Dijkstra | O((V + E) log V) |
| DP | O(N × state) |
| Binary Search | O(log N) |

## Further Reading

- [../patterns/](../patterns/) - In-depth pattern documentation
- [../docs/patterns.md](../docs/patterns.md) - Top-level pattern index
- [dsa-roadmap.md](dsa-roadmap.md) - Progressive learning path
