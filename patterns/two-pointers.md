# Two Pointers Pattern

## When to Recognize

Problems involving:
- Sorted arrays where you need to find pairs/triplets
- Opposite-direction traversal from both ends
- Finding subarrays with specific properties
- Merging sorted arrays
- Partitioning arrays

## Core Idea

Maintain two indices that move toward each other or in the same direction to satisfy constraints. This avoids nested loops by exploiting structure (sorted order, monotonicity).

## Common Complexity

- **Brute force**: $O(N^2)$ checking all pairs
- **Two pointers**: $O(N)$ on sorted arrays

## Common Variations

### Opposite-Direction Pointers
Start from both ends and move inward.

**Pattern:**
```cpp
int left = 0, right = n - 1;
while (left < right) {
    int sum = a[left] + a[right];
    if (sum == target) {
        // found
        left++;
        right--;
    } else if (sum < target) {
        left++;
    } else {
        right--;
    }
}
```

### Same-Direction Pointers
Both pointers move in the same direction, often with one leading.

**Pattern:**
```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (condition(a[fast])) {
        a[slow++] = a[fast];
    }
}
```

## Common Pitfalls

- **Infinite loops**: Incorrect pointer update logic
- **Missing conditions**: Not advancing both pointers when needed
- **Overflow risks**: Sum of two large integers
- **Sorted assumption**: Applying to unsorted arrays without sorting first

## Representative Problems

- Two-sum on sorted arrays
- Container with most water
- Three-sum (with sorting)
- Partition problems

## Related Patterns

- [Arrays](arrays.md)
- [Sliding Window](sliding-window.md)
- [Binary Search](binary-search.md)
