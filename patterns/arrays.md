# Arrays Pattern

## When to Recognize

Problems involving:
- Subarray operations (sum, product, minimum, maximum)
- Prefix and suffix computations
- Array transformations
- Frequency counting
- Two-sum or similar pair problems

## Core Idea

Leverage the index structure of arrays for efficient operations. Common techniques include:
- Prefix sums for range queries
- Two pointers for paired elements
- Sorting for greedy approaches
- Hash maps for frequency or lookup

## Common Complexity

- **Brute force**: $O(N^2)$ for all subarrays
- **Prefix sums**: $O(N)$ preprocessing, $O(1)$ range queries
- **Two pointers**: $O(N)$ on sorted arrays
- **Hash map**: $O(N)$ average

## Common Variations

### Prefix Sums
Compute cumulative sums to answer range sum queries in $O(1)$.

**Template:**
```cpp
vector<long long> prefix(n + 1, 0);
for (int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + a[i];
}
// Sum of [l, r] = prefix[r + 1] - prefix[l]
```

**See:** [templates/cpp/prefix_sums.cpp](../templates/cpp/prefix_sums.cpp)

### Difference Arrays
Apply range updates efficiently by recording differences.

**Template:**
```cpp
vector<long long> diff(n + 1, 0);
diff[l] += x;
diff[r + 1] -= x;
// Reconstruct: prefix sum over diff
```

**See:** [templates/cpp/prefix_sums.cpp](../templates/cpp/prefix_sums.cpp)

### Two Pointers
Use two indices to find pairs or subarrays meeting constraints.

**Pattern:**
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (condition(a[left], a[right])) {
        // process
        left++;
    } else {
        right--;
    }
}
```

## Common Pitfalls

- **Off-by-one errors**: Incorrect range boundaries in prefix sums
- **Integer overflow**: Use `long long` for cumulative sums
- **Index confusion**: 0-indexed vs 1-indexed arrays
- **Empty subarrays**: Consider whether empty subarrays are valid

## Representative Problems

- Prefix sum applications: Many Codeforces 800-1000 problems
- Two-pointer problems: Often in sorted array contexts
- Difference arrays: Range update problems

## Related Patterns

- [Two Pointers](two-pointers.md)
- [Sliding Window](sliding-window.md)
- [Hashing](hashing.md)
