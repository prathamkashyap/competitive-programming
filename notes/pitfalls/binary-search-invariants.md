# Binary Search Invariants

## Common Mistakes

### 1. Off-by-One in Loop Condition
```cpp
// WRONG - Infinite loop for first-true pattern
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) {
        hi = mid;
    } else {
        lo = mid + 1;
    }
}

// CORRECT - Use lo < hi for first-true
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) {
        hi = mid;
    } else {
        lo = mid + 1;
    }
}
```

### 2. Mid Calculation Overflow
```cpp
// WRONG - Overflow when lo + hi > INT_MAX
int mid = (lo + hi) / 2;

// CORRECT - No overflow
int mid = lo + (hi - lo) / 2;
```

### 3. Wrong Search Direction
```cpp
// WRONG - Decreasing hi when should increase lo
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) {
        lo = mid;  // Should be hi = mid for first-true
    } else {
        hi = mid - 1;
    }
}

// CORRECT
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) {
        hi = mid;  // Move left to find first true
    } else {
        lo = mid + 1;  // Move right past false
    }
}
```

### 4. Incorrect Monotonic Predicate
```cpp
// WRONG - Predicate is not monotonic
bool feasible(int x) {
    // May return true, false, true again
    return some_complex_condition(x);
}

// CORRECT - Ensure predicate is monotonic
// false false false true true true
bool feasible(int x) {
    return x >= threshold;
}
```

### 5. Wrong Search Bounds
```cpp
// WRONG - Bounds too narrow, misses answer
int lo = 0, hi = 1000;  // Answer might be > 1000

// CORRECT - Use appropriate bounds
int lo = 0, hi = 2e9;  // Or compute from problem constraints
```

## Common Patterns

### First True (Find minimum x where feasible(x) is true)
```cpp
int lo = lower_bound, hi = upper_bound;
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) {
        hi = mid;  // Answer is at mid or left
    } else {
        lo = mid + 1;  // Answer is to the right
    }
}
return lo;  // lo == hi == first true
```

**Invariant:** `[lo, hi]` always contains the answer, `feasible(lo-1)` is false, `feasible(hi)` is true.

### Last True (Find maximum x where feasible(x) is true)
```cpp
int lo = lower_bound, hi = upper_bound;
while (lo < hi) {
    int mid = lo + (hi - lo + 1) / 2;  // Round up
    if (feasible(mid)) {
        lo = mid;  // Answer is at mid or right
    } else {
        hi = mid - 1;  // Answer is to the left
    }
}
return lo;  // lo == hi == last true
```

**Invariant:** `[lo, hi]` always contains the answer, `feasible(lo)` is true, `feasible(hi+1)` is false.

### Standard Search (Find exact value in sorted array)
```cpp
int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == target) {
        return mid;
    } else if (a[mid] < target) {
        lo = mid + 1;
    } else {
        hi = mid - 1;
    }
}
return -1;  // Not found
```

## Invariant Checklist

Before using binary search, verify:
1. **Monotonicity**: Is the predicate truly monotonic?
2. **Bounds**: Do `lo` and `hi` definitely contain the answer?
3. **Loop condition**: `lo < hi` vs `lo <= hi`?
4. **Mid calculation**: `lo + (hi - lo) / 2` vs `(lo + hi) / 2`?
5. **Update direction**: Does `lo` increase and `hi` decrease correctly?
6. **Termination**: Will the loop definitely terminate?

## Detection

- **Infinite loop**: Loop condition or update direction wrong
- **Wrong answer**: Predicate not monotonic or bounds wrong
- **Sanity check**: Print `lo`, `hi`, `mid`, and `feasible(mid)` for small cases

## Reference

See [patterns/binary-search.md](../../patterns/binary-search.md) for binary search patterns and representative problems.
