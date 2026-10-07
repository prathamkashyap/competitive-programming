# Sliding Window Pattern

## When to Recognize

Problems involving:
- Subarrays/substrings with constraints (fixed size, at-most-K distinct elements, sum constraints)
- Consecutive elements satisfying a condition
- Minimum/maximum over all subarrays of size K

## Core Idea

Maintain a window of elements that expands and contracts while tracking aggregate information. When the window violates constraints, contract from the left.

## Common Complexity

- **Brute force**: $O(N^2)$ for all subarrays
- **Sliding window**: $O(N)$ amortized

## Common Variations

### Fixed-Size Window
Process all subarrays of fixed length K.

**Pattern:**
```cpp
int window_sum = 0;
for (int i = 0; i < n; i++) {
    window_sum += a[i];
    if (i >= K) {
        window_sum -= a[i - K];
    }
    if (i >= K - 1) {
        // process window [i-K+1, i]
    }
}
```

### Variable-Size Window (At-Most-K)
Expand right pointer, contract left when constraint violated.

**Pattern:**
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // add a[right] to window
    while (constraint_violated) {
        // remove a[left] from window
        left++;
    }
    // window [left, right] is valid
}
```

## Common Pitfalls

- **Window update order**: Remove left before adding right, or vice versa
- **Empty windows**: Handle cases where window size becomes 0
- **Duplicate counting**: Ensure elements are counted correctly when contracting
- **Index bounds**: Ensure left and right stay within array bounds

## Representative Problems

- Longest substring with at-most-K distinct characters
- Maximum sum subarray of size K
- Minimum window substring
- Subarray product less than K

**See:** [templates/cpp/sliding_window.cpp](../templates/cpp/sliding_window.cpp)

## Related Patterns

- [Arrays](arrays.md)
- [Two Pointers](two-pointers.md)
- [Hashing](hashing.md)
