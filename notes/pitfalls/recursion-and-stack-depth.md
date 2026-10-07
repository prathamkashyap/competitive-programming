# Recursion and Stack Depth

## Common Mistakes

### 1. Deep Recursion on Large Input
```cpp
// WRONG - Stack overflow on n = 10^5
void dfs(int node) {
    for (int child : adj[node]) {
        dfs(child);  // Depth can be N in worst case
    }
}

// CORRECT - Use iterative DFS or increase stack limit
void dfs_iterative(int start) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int node = st.top(); st.pop();
        for (int child : adj[node]) {
            st.push(child);
        }
    }
}
```

### 2. Infinite Recursion
```cpp
// WRONG - No base case or incorrect base case
int factorial(int n) {
    return n * factorial(n - 1);  // Never reaches base case
}

// CORRECT
int factorial(int n) {
    if (n <= 1) return 1;  // Base case
    return n * factorial(n - 1);
}
```

### 3. Missing Memoization in Overlapping Subproblems
```cpp
// WRONG - Exponential time
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// CORRECT - O(N) with memoization
vector<int> memo(100, -1);
int fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
```

### 4. Not Increasing Recursion Limit (Python)
```python
# WRONG - Default recursion limit is ~1000
def dfs(node):
    for child in adj[node]:
        dfs(child)  # RecursionError on deep trees

# CORRECT
import sys
sys.setrecursionlimit(10**6)
def dfs(node):
    for child in adj[node]:
        dfs(child)
```

## Stack Depth Limits

### C++
- Default stack size: ~1-8 MB (system-dependent)
- Typical function call overhead: ~16-64 bytes
- Maximum safe depth: ~10^4-10^5 for simple functions
- Deep recursion on 10^5 nodes will overflow

### Python
- Default recursion limit: 1000
- Increase with `sys.setrecursionlimit(10**6)`
- Still limited by system stack size

## When to Use Iterative Instead

- **Depth can exceed 10^4**: Use iterative
- **Worst-case skewed tree**: Use iterative
- **Unknown depth**: Use iterative or increase stack limit
- **Performance critical**: Iterative may be faster

## Conversion to Iterative

### Recursive to Iterative (DFS)
```cpp
// Recursive
void dfs(int node) {
    visited[node] = true;
    for (int child : adj[node]) {
        if (!visited[child]) {
            dfs(child);
        }
    }
}

// Iterative
void dfs_iterative(int start) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (int child : adj[node]) {
            if (!visited[child]) {
                st.push(child);
            }
        }
    }
}
```

## Detection

- **Runtime error / segmentation fault**: Stack overflow
- **RecursionError (Python)**: Exceeded recursion limit
- **Sanity check**: Print depth or use iterative version for comparison

## Prevention

- Use iterative DFS/BFS for large graphs
- Increase recursion limit in Python with `sys.setrecursionlimit`
- Test on maximum input size
- Use tail recursion where applicable (compiler may optimize)

## Reference

See [patterns/recursion-backtracking.md](../../patterns/recursion-backtracking.md) for recursion patterns.
