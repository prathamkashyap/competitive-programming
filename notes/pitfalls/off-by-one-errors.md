# Off-by-One Errors

## Common Mistakes

### 1. Array Indexing
```cpp
// WRONG
for (int i = 0; i <= n; i++) {  // Accesses a[n], out of bounds
    cout << a[i] << '\n';
}

// CORRECT
for (int i = 0; i < n; i++) {
    cout << a[i] << '\n';
}
```

### 2. Prefix Sum Boundaries
```cpp
// WRONG
int sum = prefix[r] - prefix[l];  // Should be prefix[r+1] - prefix[l]

// CORRECT
int sum = prefix[r + 1] - prefix[l];
```

### 3. Loop Conditions
```cpp
// WRONG
while (lo <= hi) {  // For first-true pattern, should be lo < hi
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) hi = mid;
    else lo = mid + 1;
}

// CORRECT
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid)) hi = mid;
    else lo = mid + 1;
}
```

### 4. String Termination
```cpp
// WRONG
for (int i = 0; i <= strlen(s); i++) {  // Goes past null terminator
    process(s[i]);
}

// CORRECT
for (int i = 0; i < strlen(s); i++) {
    process(s[i]);
}
```

### 5. Sliding Window Bounds
```cpp
// WRONG
int window_sum = 0;
for (int i = 0; i < n; i++) {
    window_sum += a[i];
    if (i >= K) {  // Should be i >= K-1 to start processing
        window_sum -= a[i - K];
    }
}

// CORRECT
for (int i = 0; i < n; i++) {
    window_sum += a[i];
    if (i >= K) {
        window_sum -= a[i - K];
    }
    if (i >= K - 1) {
        // process window
    }
}
```

## Common Patterns

### 0-indexed vs 1-indexed
- Arrays in C++ are 0-indexed
- Many competitive programming problems use 1-indexed input
- Adjust when reading: `a[i] = value;` vs `a[i-1] = value;`

### Inclusive vs Exclusive Ranges
- Many functions use inclusive start, exclusive end: `[l, r)`
- Prefix sums typically use `[0, n)` for n elements
- Be consistent

### Binary Search Variants
- First true: `while (lo < hi)`, `hi = mid`, `lo = mid + 1`
- Last true: `while (lo < hi)`, `lo = mid`, `hi = mid - 1`
- Standard search: `while (lo <= hi)`

## Detection

- **Segmentation fault**: Array out of bounds
- **Wrong answer by 1**: Off-by-one in loop or condition
- **Sanity check**: Print loop bounds and indices for small cases

## Prevention

- Use range-based for loops when possible: `for (int x : a)`
- Test on small inputs (n = 1, 2, 3)
- Add assertions: `assert(0 <= index && index < n)`
- Use `at()` instead of `[]` for debugging (throws on out of bounds)

## Reference

See [patterns/binary-search.md](../../patterns/binary-search.md) for binary search invariants.
