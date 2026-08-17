# 💡 Dynamic Programming Patterns & Optimizations

## 1. Classical DP Patterns

### 1. 0/1 Knapsack & Subset Sum
- **State**: `dp[i][w]` = maximum value using a subset of first $i$ items with total weight $\le w$.
- **Space Optimization**: Can reduce to 1D array iterating weights backwards from $W$ down to $w_i$.
```cpp
vector<long long> dp(W + 1, 0);
for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
        dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
    }
}
```

### 2. Longest Increasing Subsequence (LIS) in $O(N \log N)$
Maintain the smallest tail element of all increasing subsequences of length $L$:
```cpp
vector<int> lis;
for (int x : arr) {
    auto it = lower_bound(lis.begin(), lis.end(), x);
    if (it == lis.end()) lis.push_back(x);
    else *it = x;
}
int length = lis.size();
```

### 3. Grid Paths & Matrix DP
- **State**: `dp[i][j]` = number of paths or minimum cost to reach cell $(i, j)$ from $(0, 0)$.
- **Transition**: `dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]`

---

## 2. Common DP Optimizations

- **Prefix Sum Optimization**: When $dp[i][j] = \sum_{k} dp[i-1][k]$, use a prefix sum array to reduce transition time from $O(K)$ to $O(1)$.
- **Space Reduction**: If state only depends on row $i-1$, keep only two rows (`dp[2][W]`) or a single 1D array.
- **Bitmask State Compression**: Represent sets of visited nodes or taken items as bit integers ($0 \le mask < 2^N$).

---

[← Back to Notes](README.md)
