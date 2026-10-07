# Complexity Reference

A concise complexity reference for interview discussions.

## Time Complexity

### Common Operations

| Operation | Complexity |
|-----------|------------|
| Array access | O(1) |
| Array search (linear) | O(N) |
| Binary search | O(log N) |
| Hash map insert/lookup | O(1) average |
| Sorting | O(N log N) |
| Stack/Queue push/pop | O(1) |
| Linked list access | O(N) |
| Linked list insert at head | O(1) |

### Common Algorithms

| Algorithm | Complexity |
|-----------|------------|
| BFS | O(V + E) |
| DFS | O(V + E) |
| Dijkstra | O((V + E) log V) |
| Bellman-Ford | O(VE) |
| Floyd-Warshall | O(V^3) |
| Kruskal's MST | O(E log E) |
| Prim's MST | O((V + E) log V) |
| KMP string matching | O(N + M) |
| Sieve of Eratosthenes | O(N log log N) |

### Dynamic Programming

| Pattern | Complexity |
|---------|------------|
| 0/1 Knapsack | O(NW) |
| LIS (O(N log N)) | O(N log N) |
| LCS | O(NM) |
| Grid DP | O(NM) |
| Bitmask DP | O(N × 2^N) |

## Space Complexity

| Data Structure | Space |
|---------------|-------|
| Array | O(N) |
| Hash map | O(N) |
| Stack/Queue | O(N) |
| Linked list | O(N) |
| Tree | O(N) |
| Graph adjacency list | O(V + E) |
| Graph adjacency matrix | O(V^2) |
| Segment tree | O(4N) |
| Fenwick tree | O(N) |

## Complexity Classes

| Class | Description | Example |
|-------|-------------|---------|
| O(1) | Constant | Array access |
| O(log N) | Logarithmic | Binary search |
| O(N) | Linear | Single pass |
| O(N log N) | Linearithmic | Sorting |
| O(N^2) | Quadratic | Nested loops |
| O(2^N) | Exponential | Brute force subsets |
| O(N!) | Factorial | Permutations |

## Interview Discussion Points

### When Asked About Complexity

1. **State both time and space**: Don't forget space complexity
2. **Explain trade-offs**: Faster time may use more space
3. **Consider constraints**: Discuss what happens with N = 10^5 vs N = 10^6
4. **Mention best/worst/average**: Especially for hash maps and quicksort
5. **Be precise**: O(N log N) is different from O(N^2)

### Common Questions

**"Can you optimize this?"**
- Look for:
  - Hash map instead of nested loops
  - Binary search instead of linear search
  - Prefix sums instead of repeated calculations
  - DP instead of brute force

**"What if N is very large?"**
- Consider:
  - O(N log N) vs O(N^2) matters
  - Memory constraints
  - Integer overflow
  - Need for streaming algorithms

**"Can you reduce space?"**
- Look for:
  - 1D array instead of 2D
  - Reusing variables
  - Iterative instead of recursive (no call stack)
  - Bit manipulation

## Complexity Estimation

### Operations per Second
- ~10^8 simple operations per second
- ~10^7 moderate operations per second
- ~10^6 heavy operations per second

### Time Limits by N
| N | Expected Complexity |
|---|---------------------|
| 10^5 | O(N), O(N log N) |
| 10^6 | O(N), O(N log N) (tight) |
| 10^7 | O(N) (very tight) |
| 10^3 | O(N^2), O(N^2 log N) |
| 10^2 | O(N^3), O(2^N) |

## Reference

- [../notes/complexity_and_limits.md](../notes/complexity_and_limits.md) - Detailed complexity notes
- [../notes/pitfalls/complexity-mistakes.md](../notes/pitfalls/complexity-mistakes.md) - Common complexity mistakes
