# Curated Interview Problems

A curated set of representative problems from this repository for interview preparation.

This is a focused subset, not an exhaustive list. Quality over quantity.

## Arrays

### Prefix Sums
- [codeforces/1100/1832B_MaximumSum.cpp](../codeforces/1100/1832B_MaximumSum.cpp) - Prefix sums with sorting
- [codeforces/1100/313B_IlyaandQueries.cpp](../codeforces/1100/313B_IlyaandQueries.cpp) - Prefix sums on string
- [codeforces/1200/433B_KuriyamaMirai'sStones.cpp](../codeforces/1200/433B_KuriyamaMirai'sStones.cpp) - Prefix sums on original and sorted arrays

**Template**: [templates/cpp/prefix_sums.cpp](../templates/cpp/prefix_sums.cpp)

## Binary Search

### Binary Search on Answer
- [codeforces/1100/1850E_CardboardforPictures.cpp](../codeforces/1100/1850E_CardboardforPictures.cpp) - Binary search on width
- [codeforces/1100/1873E_BuildinganAquarium.cpp](../codeforces/1100/1873E_BuildinganAquarium.cpp) - Binary search on height
- [codeforces/1200/1613C_PoisonedDagger.cpp](../codeforces/1200/1613C_PoisonedDagger.cpp) - Binary search on k

**Pattern**: [patterns/binary-search.md](../patterns/binary-search.md)

## Graphs

### BFS (Shortest Path)
- Many Codeforces 800-900 problems use BFS for grid shortest path
- Check [codeforces/800/](../codeforces/800/) for examples

### Dijkstra
- Template: [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)
- Representative problems in codeforces/1200-1300

**Template**: [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)

## Dynamic Programming

### Grid DP
- Many problems in codeforces/1200-1300 use 2D DP
- Look for problems with 2D grid or matrix structure

### LIS and LCS
- Template for LIS with binary search in [patterns/dynamic-programming.md](../patterns/dynamic-programming.md)
- Codeforces problems in 1200-1300 range

**Pattern**: [patterns/dynamic-programming.md](../patterns/dynamic-programming.md)

## Number Theory

### Modular Arithmetic
- Template: [templates/cpp/modular_arithmetic.cpp](../templates/cpp/modular_arithmetic.cpp)
- Problems involving nCr, factorial modulo prime in codeforces/1300

### Sieve
- Template: [templates/cpp/sieve_prime.cpp](../templates/cpp/sieve_prime.cpp)
- Prime factorization problems in codeforces/1200-1300

**Templates**:
- [templates/cpp/modular_arithmetic.cpp](../templates/cpp/modular_arithmetic.cpp)
- [templates/cpp/sieve_prime.cpp](../templates/cpp/sieve_prime.cpp)

## Data Structures

### DSU (Disjoint Set Union)
- Template: [templates/cpp/dsu.cpp](../templates/cpp/dsu.cpp)
- Connectivity problems in codeforces/1200-1300

### Segment Tree
- Template: [templates/cpp/segment_tree.cpp](../templates/cpp/segment_tree.cpp)
- Range query problems in codeforces/1300-1400

### Fenwick Tree
- Template: [templates/cpp/fenwick_tree.cpp](../templates/cpp/fenwick_tree.cpp)
- Prefix sum with update problems

**Templates**:
- [templates/cpp/dsu.cpp](../templates/cpp/dsu.cpp)
- [templates/cpp/segment_tree.cpp](../templates/cpp/segment_tree.cpp)
- [templates/cpp/fenwick_tree.cpp](../templates/cpp/fenwick_tree.cpp)

## Sliding Window

- Template: [templates/cpp/sliding_window.cpp](../templates/cpp/sliding_window.cpp)
- Subarray constraint problems in codeforces/1000-1200

**Template**: [templates/cpp/sliding_window.cpp](../templates/cpp/sliding_window.cpp)

## Greedy

- Interval scheduling problems in codeforces/1000-1200
- Sorting-based selection problems
- See [patterns/greedy.md](../patterns/greedy.md) for patterns

**Pattern**: [patterns/greedy.md](../patterns/greedy.md)

## Practice Strategy

1. **Start with templates**: Understand reusable components
2. **Practice by difficulty**: 800 → 900 → 1000 → 1100 → 1200
3. **Focus on patterns**: Recognize problem shapes
4. **Review pitfalls**: Check [notes/pitfalls/](../notes/pitfalls/) for common mistakes

## Complete Index

For the complete problem index, see [docs/generated/problem-index.md](../docs/generated/problem-index.md).

## Further Reading

- [dsa-roadmap.md](dsa-roadmap.md) - Progressive learning path
- [patterns.md](patterns.md) - Quick recognition guide
- [../patterns/](../patterns/) - In-depth pattern documentation
