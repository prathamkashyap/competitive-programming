# DP State Definition

## Common Mistakes

### 1. State Doesn't Capture All Information
```cpp
// WRONG - State only tracks position, not enough information
int dp[n];  // dp[i] = max value considering first i items
// But need to know whether item i was taken or not

// CORRECT - Include all necessary dimensions
int dp[n + 1][W + 1];  // dp[i][w] = max value using first i items with weight w
```

### 2. Incorrect Transition Direction
```cpp
// WRONG - Transition in wrong direction
for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
        if (w >= weight[i]) {
            dp[i][w] = max(dp[i][w], dp[i-1][w - weight[i]] + value[i]);
        }
    }
}

// CORRECT - Use previous state correctly
for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
        dp[i][w] = dp[i-1][w];  // Don't take item i
        if (w >= weight[i]) {
            dp[i][w] = max(dp[i][w], dp[i-1][w - weight[i]] + value[i]);
        }
    }
}
```

### 3. Missing Base Cases
```cpp
// WRONG - No base case initialization
int dp[n + 1][m + 1];
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        // transition
    }
}

// CORRECT - Initialize base cases
int dp[n + 1][m + 1];
for (int i = 0; i <= n; i++) dp[i][0] = 0;  // Empty string
for (int j = 0; j <= m; j++) dp[0][j] = 0;  // Empty string
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        // transition
    }
}
```

### 4. Wrong Order of Computation
```cpp
// WRONG - Computing in wrong order leads to using uninitialized values
for (int i = n; i >= 1; i--) {
    for (int w = 0; w <= W; w++) {
        dp[i][w] = max(dp[i][w], dp[i-1][w - weight[i]] + value[i]);
    }
}

// CORRECT - Compute in dependency order
for (int i = 1; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
        dp[i][w] = max(dp[i][w], dp[i-1][w - weight[i]] + value[i]);
    }
}
```

### 5. State Too Large (Memory Limit)
```cpp
// WRONG - State too large for memory
int dp[1000][1000][1000];  // 10^9 integers, exceeds memory

// CORRECT - Reduce state or use space optimization
int dp[2][1000][1000];  // Rolling array if only previous state needed
// or use 1D optimization
int dp[W + 1];
for (int i = 1; i <= n; i++) {
    for (int w = W; w >= weight[i]; w--) {
        dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
    }
}
```

## State Design Guidelines

### What Should Be in State?
1. **Position in input**: Index i, j, etc.
2. **Resources remaining**: Weight, time, capacity
3. **Choices made so far**: Flags, parity, mod values
4. **Constraints**: What distinguishes different subproblems?

### State Size Estimation
- Total states = product of state dimensions
- Memory = states × bytes per state
- Time = states × transition cost
- Ensure both fit within limits

### Common State Patterns

| Problem | State |
|---------|-------|
| Knapsack | `dp[i][w]` - first i items, weight w |
| LIS | `dp[i]` - LIS ending at index i |
| LCS | `dp[i][j]` - first i chars of s1, first j chars of s2 |
| Grid DP | `dp[i][j]` - position (i, j) |
| String DP | `dp[l][r]` - substring from l to r |
| Bitmask DP | `dp[mask][i]` - visited set mask, last position i |

## Transition Design

### Questions to Ask
1. What choices do I have at this state?
2. What states can I transition to?
3. What is the cost/value of each transition?
4. What is the recurrence relation?

### Common Transition Types
- **Max/Min**: `dp[state] = max/min(dp[next_state] + cost)`
- **Counting**: `dp[state] = sum(dp[next_state])`
- **Boolean**: `dp[state] = dp[next_state1] || dp[next_state2]`

## Space Optimization

### When Can We Optimize?
- When transition only depends on previous state(s)
- When we only need final answer, not all intermediate states

### Techniques
- **1D array**: Replace 2D when one dimension is just "previous"
- **Rolling array**: Keep only last K states
- **Coordinate compression**: Reduce state space
- **Bit manipulation**: Pack multiple states into integer

## Detection

- **WA**: Wrong state definition or transition
- **MLE**: State too large
- **TLE**: Too many states or expensive transitions
- **Sanity check**: Print dp table for small input

## Reference

See [patterns/dynamic-programming.md](../../patterns/dynamic-programming.md) for DP patterns and [notes/dynamic_programming.md](../dynamic_programming.md) for examples.
