# Greedy & Binary Search Patterns

A contest-time guide to recognizing two of the most reusable algorithmic patterns.

## 1. Greedy Choice

A greedy algorithm commits to the locally best option and never revisits that
choice. It is correct only when the choice can be justified globally.

### Proof checklist

1. **Define the choice**: What is the locally optimal action?
2. **Exchange argument**: Take an optimal solution and replace its first choice
   with the greedy choice without making it worse.
3. **Reduce the problem**: Show that the remaining suffix is the same kind of
   problem.
4. **Stop condition**: Explain why every item is processed exactly once.

### Common signals

| Signal | Typical greedy choice |
| :--- | :--- |
| Maximize the number of non-overlapping intervals | Choose the interval with the earliest finishing time |
| Minimize the number of resources | Sort events and sweep starts/ends |
| Build the largest/smallest arrangement | Sort by a comparator and place the best next item |
| Repeatedly merge values | Use a min-heap to select the two smallest |
| Reach a target with local jumps | Track the farthest reachable position |

### Interval scheduling

For maximum non-overlapping intervals, sort by `right endpoint` and accept an
interval when `left >= last_right`. The exchange argument is that any optimal
schedule can replace its first interval with the interval that finishes first.

Complexity: $O(n \log n)$ for sorting and $O(n)$ for the sweep.

## 2. Binary Search on a Monotonic Predicate

Binary search is not limited to finding a value in a sorted array. It can find
the smallest or largest answer for which a feasibility predicate changes state.

```text
false false false true true true
                  ^ first true
```

### Template: first feasible answer

```cpp
long long lo = lower_bound_answer;
long long hi = upper_bound_answer;
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

The key work is designing `feasible(x)` so that it is monotonic. Typical
examples include minimum capacity, minimum maximum distance, maximum minimum
value, and the K-th feasible value.

### Avoiding overflow

Use `lo + (hi - lo) / 2`, and use a wide type for products and prefix sums.
For a predicate involving division, rewrite inequalities when possible:
`a / x >= k` can often be checked as `a >= k * x`, provided the multiplication
uses a wide type.

## 3. Two-Pointer Greedy

After sorting, maintain a left and right pointer and discard states that can
no longer improve the answer. The proof usually comes from monotonicity: when
a pointer moves, it never needs to move backward.

Typical uses:

- Pair sum and three-sum variants
- Minimum window after sorting
- Merging intervals
- Fast/slow traversal of sequences
- Sliding-window constraints

## 4. Contest Checklist

- Can the input be sorted without changing the answer?
- Is there an earliest/latest boundary that dominates all alternatives?
- Can I express the answer as a monotonic yes/no predicate?
- What invariant remains true after each pointer or greedy choice?
- Have I tested empty input, one element, duplicate values, and boundary answers?
