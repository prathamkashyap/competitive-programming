# Greedy Pattern

## When to Recognize

Problems involving:
- Scheduling (intervals, tasks)
- Selection problems where local choices seem optimal
- Problems with exchange-argument proofs
- Sorting-based solutions
- Minimizing/maximizing with simple criteria

## Core Idea

Make the locally optimal choice at each step, assuming (and proving) that this leads to a global optimum. Greedy algorithms are often simple but require proof of correctness.

## Common Complexity

- **Brute force**: Exponential
- **Greedy**: $O(N \log N)$ after sorting

## Common Variations

### Exchange Argument
Prove that any optimal solution can be transformed into the greedy solution by exchanging elements.

**Pattern:**
```cpp
sort(a.begin(), a.end());
for (auto x : a) {
    if (can_take(x)) {
        take(x);
    }
}
```

### Interval Scheduling
Select maximum number of non-overlapping intervals.

**Pattern:**
```cpp
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
    return a.end < b.end;
});
int count = 0, last_end = -INF;
for (auto& interval : intervals) {
    if (interval.start >= last_end) {
        count++;
        last_end = interval.end;
    }
}
```

### Fractional Knapsack
Take items by value-to-weight ratio.

**Pattern:**
```cpp
sort(items.begin(), items.end(), [](auto& a, auto& b) {
    return a.value / a.weight > b.value / b.weight;
});
```

## Common Pitfalls

- **Assuming greedy works without proof**: Many problems that look greedy are actually DP
- **Incorrect sorting criteria**: The wrong sort order breaks the greedy property
- **Missing edge cases**: Greedy may fail on specific input patterns
- **Counterexamples**: Always try to find a counterexample before committing to greedy

## Representative Problems

- Interval scheduling
- Activity selection
- Minimum spanning tree (Kruskal's is greedy with DSU)
- Huffman coding

**See:** [notes/greedy_and_search.md](../notes/greedy_and_search.md)

## Related Patterns

- [Binary Search](binary-search.md)
- [Arrays](arrays.md)
- [Graphs](graphs.md) - MST via Kruskal's

## Proof Strategies

1. **Exchange argument**: Show any optimal solution can be transformed into greedy solution
2. **Matroid theory**: Some greedy problems can be formalized as matroids
3. **Cut property**: For MST, greedy on minimum edge crossing a cut is optimal
4. **Induction**: Prove by induction on problem size

**Always verify with small examples and attempt to find counterexamples.**
