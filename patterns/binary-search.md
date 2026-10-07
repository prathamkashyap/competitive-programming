# Binary Search Pattern

## When to Recognize

Problems involving:
- Finding a value in a sorted array
- Monotonic search space (answers can be ordered)
- Optimization problems where feasibility is monotonic
- Finding the minimum/maximum value satisfying a condition

## Core Idea

Repeatedly halve the search space based on a feasibility predicate. For arrays, this is the standard binary search. For optimization, this is "binary search on answer."

## Common Complexity

- **Linear search**: $O(N)$
- **Binary search**: $O(\log N)$

## Common Variations

### Standard Binary Search
Find a value in a sorted array.

**Pattern:**
```cpp
int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) return mid;
    else if (a[mid] < target) lo = mid + 1;
    else hi = mid - 1;
}
```

### Binary Search on Answer (First True)
Find the smallest value where a predicate becomes true.

**Pattern:**
```cpp
long long lo = lower_bound, hi = upper_bound;
while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (feasible(mid)) {
        hi = mid;
    } else {
        lo = mid + 1;
    }
}
return lo;
```

**Representative:** [codeforces/1200/1613C_PoisonedDagger.cpp](../codeforces/1200/1613C_PoisonedDagger.cpp)

### Binary Search on Answer (Last True)
Find the largest value where a predicate remains true.

**Pattern:**
```cpp
long long lo = lower_bound, hi = upper_bound;
while (lo < hi) {
    long long mid = lo + (hi - lo + 1) / 2;
    if (feasible(mid)) {
        lo = mid;
    } else {
        hi = mid - 1;
    }
}
return lo;
```

## Common Pitfalls

- **Off-by-one in loop condition**: `lo < hi` vs `lo <= hi`
- **Overflow in mid calculation**: Use `lo + (hi - lo) / 2` not `(lo + hi) / 2`
- **Incorrect predicate monotonicity**: Ensure predicate is truly monotonic
- **Wrong search bounds**: Lower/upper bounds may be very large or negative

**See:** [notes/pitfalls/binary-search-invariants.md](../notes/pitfalls/binary-search-invariants.md)

## Representative Problems

- Binary search on answer: [codeforces/1100/1850E_CardboardforPictures.cpp](../codeforces/1100/1850E_CardboardforPictures.cpp)
- Binary search on answer: [codeforces/1100/1873E_BuildinganAquarium.cpp](../codeforces/1100/1873E_BuildinganAquarium.cpp)
- Binary search on answer: [codeforces/1200/1613C_PoisonedDagger.cpp](../codeforces/1200/1613C_PoisonedDagger.cpp)

## Related Patterns

- [Greedy](greedy.md)
- [Arrays](arrays.md)

**See:** [notes/greedy_and_search.md](../notes/greedy_and_search.md)
