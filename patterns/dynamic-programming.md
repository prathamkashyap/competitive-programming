# Dynamic Programming Pattern

## When to Recognize

Problems involving:
- Overlapping subproblems
- Optimal substructure
- Counting possibilities
- Optimization with repeated choices
- Problems that can be broken into smaller instances

## Core Idea

Solve subproblems once and memoize or tabulate results, building up to the final answer. Avoid recomputation by storing intermediate results.

## Common Complexity

- **Brute force**: Exponential
- **DP with memoization**: $O(N \times state)$
- **DP with tabulation**: $O(N \times state)$

## Common Variations

### 0/1 Knapsack
Select items with maximum value under weight constraint.

**Pattern:**
```cpp
vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
        if (weight[i] <= w) {
            dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i]);
        } else {
            dp[i][w] = dp[i-1][w];
        }
    }
}
```

### Longest Increasing Subsequence (LIS)
Find longest strictly increasing subsequence.

**Pattern ($O(N \log N)$):**
```cpp
vector<int> lis;
for (int x : a) {
    auto it = lower_bound(lis.begin(), lis.end(), x);
    if (it == lis.end()) lis.push_back(x);
    else *it = x;
}
```

### Longest Common Subsequence (LCS)
Find longest common subsequence between two strings.

**Pattern:**
```cpp
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (s1[i-1] == s2[j-1]) {
            dp[i][j] = dp[i-1][j-1] + 1;
        } else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
```

### Grid DP
2D grid problems with movement constraints.

**Pattern:**
```cpp
vector<vector<int>> dp(n, vector<int>(m, 0));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        dp[i][j] = grid[i][j];
        if (i > 0) dp[i][j] += dp[i-1][j];
        if (j > 0) dp[i][j] += dp[i][j-1];
        if (i > 0 && j > 0) dp[i][j] -= dp[i-1][j-1];
    }
}
```

### Space Optimization
Reduce space from $O(N \times state)$ to $O(state)$.

**Pattern:**
```cpp
vector<int> dp(W + 1, 0);
for (int i = 1; i <= n; i++) {
    for (int w = W; w >= weight[i]; w--) {
        dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
    }
}
```

## Common Pitfalls

- **Incorrect state definition**: State must capture all necessary information
- **Transition errors**: Incorrect recurrence relation
- **Base cases**: Missing or incorrect initialization
- **Memory limits**: 2D/3D DP may exceed memory
- **Order of computation**: Tabulation order matters (dependencies)

**See:** [notes/pitfalls/dp-state-definition.md](../notes/pitfalls/dp-state-definition.md)

## Optimization Techniques

- **Space optimization**: Use 1D array when possible
- **Coordinate compression**: Reduce state space
- **Divide and conquer DP**: For certain DP formulations
- **Monotonic queue optimization**: For DP with range constraints

## Representative Problems

- 0/1 Knapsack
- LIS, LCS
- Edit distance
- Coin change
- Matrix chain multiplication

**See:** [notes/dynamic_programming.md](../notes/dynamic_programming.md)

## Related Patterns

- [Recursion](recursion-backtracking.md) - Memoization turns recursion into DP
- [Greedy](greedy.md) - Some greedy problems are actually DP
