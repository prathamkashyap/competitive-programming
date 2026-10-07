# Graph Traversal Mistakes

## Common Mistakes

### 1. Not Tracking Parent in Undirected Graphs
```cpp
// WRONG - Infinite loop on undirected graph
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// CORRECT - Track parent to avoid going back
void dfs(int u, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (v != parent && !visited[v]) {
            dfs(v, u);
        }
    }
}
```

### 2. Stack Overflow on Deep Recursion
```cpp
// WRONG - DFS on large graph with recursion
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);  // Stack overflow on 10^5 nodes
        }
    }
}

// CORRECT - Use iterative DFS
void dfs_iterative(int start) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                st.push(v);
            }
        }
    }
}
```

### 3. Incorrect Distance Initialization
```cpp
// WRONG - Using 0 as initial distance
vector<int> dist(n + 1, 0);
dist[start] = 0;
// BFS will think all unvisited nodes are at distance 0

// CORRECT - Use -1 or INF
vector<int> dist(n + 1, -1);
dist[start] = 0;
```

### 4. Forgetting to Clear Data Structures Between Test Cases
```cpp
// WRONG - Data persists between test cases
int t;
cin >> t;
while (t--) {
    int n, m;
    cin >> n >> m;
    // adj from previous test case still has old edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // process
}

// CORRECT - Clear data structures
int t;
cin >> t;
while (t--) {
    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    visited.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    // process
}
```

### 5. Dijkstra on Negative Weights
```cpp
// WRONG - Dijkstra fails with negative edge weights
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
// ... standard Dijkstra ...
// Fails if any edge weight is negative

// CORRECT - Use Bellman-Ford for negative weights
vector<long long> dist(n + 1, INF);
dist[start] = 0;
for (int i = 0; i < n - 1; i++) {
    for (auto [u, v, w] : edges) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
        }
    }
}
```

## Common Graph Issues

### Disconnected Graphs
- BFS/DFS from a single node won't visit all nodes
- Need to iterate over all nodes: `for (int i = 1; i <= n; i++) if (!visited[i]) dfs(i)`

### Self-Loops
- Can cause infinite loops if not handled
- Check `if (u != v)` when adding edges

### Multiple Edges
- May affect shortest path algorithms
- Usually harmless, but consider for MST (Kruskal handles them)

### 1-indexed vs 0-indexed
- Problem statements often use 1-indexed nodes
- C++ arrays are 0-indexed
- Adjust accordingly

## BFS vs DFS

### BFS (Unweighted Shortest Path)
- Guarantees shortest path in unweighted graphs
- Uses queue
- Level-order traversal

### DFS (Connectivity, Cycles)
- Not guaranteed shortest path
- Uses stack or recursion
- Explores depth-first

## Detection

- **TLE**: Inefficient traversal or infinite loop
- **WA**: Wrong distance, visited incorrectly
- **Runtime error**: Stack overflow (recursive DFS)
- **Sanity check**: Print visited count, check if equals N

## Reference

See [patterns/graphs.md](../../patterns/graphs.md) for graph patterns and [templates/cpp/graph_traversal.cpp](../../templates/cpp/graph_traversal.cpp) for templates.
