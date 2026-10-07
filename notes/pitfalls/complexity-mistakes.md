# Complexity Mistakes

## Common Mistakes

### 1. Nested Loops in O(N) Problems
```cpp
// WRONG - O(N^2) when O(N) is expected
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (a[i] == a[j]) count++;
    }
}

// CORRECT - O(N) with hash map
unordered_map<int, int> freq;
for (int i = 0; i < n; i++) {
    freq[a[i]]++;
}
```

### 2. Sorting in Problems Requiring O(N)
```cpp
// WRONG - O(N log N) when O(N) is possible
sort(a.begin(), a.end());
// then linear scan

// CORRECT - Use counting sort or hash map if range is small
vector<int> count(max_val + 1, 0);
for (int x : a) count[x]++;
```

### 3. Repeated String Operations
```cpp
// WRONG - O(N^2) due to string concatenation
string s;
for (int i = 0; i < n; i++) {
    s += 'x';  // Each concatenation copies entire string
}

// CORRECT - O(N) with reserve or use vector
s.reserve(n);
for (int i = 0; i < n; i++) {
    s += 'x';
}
```

### 4. Ignoring Constant Factors
```cpp
// WRONG - O(N^2) due to hidden constant
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // Expensive operation inside
        vector<int> temp(n);  // O(N) per iteration = O(N^3) total
    }
}

// CORRECT - Move expensive operation outside
vector<int> temp(n);
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        // Use precomputed temp
    }
}
```

### 5. Recursion Without Memoization
```cpp
// WRONG - Exponential time
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// CORRECT - O(N) with memoization
vector<int> memo(n + 1, -1);
int fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
```

## Complexity Guidelines

### Operations per Second
- ~10^8 simple operations per second
- ~10^7 moderate operations per second
- ~10^6 heavy operations per second

### Time Limits by N
| N | Expected Complexity |
|---|---------------------|
| 10^5 | O(N), O(N log N) |
| 10^6 | O(N), O(N log N) (tight) |
| 10^7 | O(N) (very tight) |
| 10^3 | O(N^2), O(N^2 log N) |
| 10^2 | O(N^3), O(2^N) |

### Space Limits
- Typical: 256 MB or 512 MB
- int: 4 bytes
- long long: 8 bytes
- vector<int> of size 10^7: ~40 MB
- vector<vector<int>> of 10^5 × 10^5: Will exceed memory

## Common Complexities

- **Sorting**: O(N log N)
- **Hash map operations**: O(1) average, O(N) worst-case
- **Binary search**: O(log N)
- **BFS/DFS**: O(V + E)
- **Dijkstra**: O((V + E) log V)
- **DP**: O(N × state)

## Detection

- **TLE (Time Limit Exceeded)**: Complexity too high
- **MLE (Memory Limit Exceeded)**: Space too high
- **Sanity check**: Calculate worst-case operations and compare to limit

## Optimization Strategies

1. **Choose right data structure**: hash map vs tree vs array
2. **Precompute**: Sort once, reuse results
3. **Reduce state**: DP state space optimization
4. **Prune**: Cut off impossible branches in recursion
5. **Use bit operations**: Bitmasks for small sets

## Reference

See [notes/complexity_and_limits.md](../complexity_and_limits.md) for more on limits and operations per second.
