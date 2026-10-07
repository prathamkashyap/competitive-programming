# Graphs Pattern

## When to Recognize

Problems involving:
- Networks, connectivity, paths
- Grid-based movement
- Relationships between entities
- Flow, matching, or optimization on networks
- Tree structures (trees are graphs)

## Core Idea

Model relationships as vertices and edges. Apply traversal (BFS/DFS), shortest-path, or advanced graph algorithms based on problem requirements.

## Common Complexity

- **BFS/DFS**: $O(V + E)$
- **Dijkstra**: $O((V + E) \log V)$ with priority queue
- **Floyd-Warshall**: $O(V^3)$
- **Kruskal's MST**: $O(E \log E)$

## Common Variations

### BFS (Unweighted Shortest Path)
Find shortest path in unweighted graphs.

**Pattern:**
```cpp
queue<int> q;
vector<int> dist(n + 1, -1);
dist[start] = 0;
q.push(start);
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

**See:** [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)

### Dijkstra (Weighted Shortest Path)
Find shortest path with non-negative edge weights.

**Pattern:**
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
vector<long long> dist(n + 1, INF);
dist[start] = 0;
pq.push({0, start});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
```

**See:** [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)

### DFS (Connectivity, Cycles)
Explore all reachable nodes, detect cycles.

**Pattern:**
```cpp
vector<bool> visited(n + 1, false);
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}
```

### Topological Sort
Order vertices in DAG respecting edge directions.

**Pattern:**
```cpp
vector<int> indegree(n + 1, 0);
queue<int> q;
for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) q.push(i);
}
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (--indegree[v] == 0) q.push(v);
    }
}
```

**See:** [templates/cpp/graph_traversal.cpp](../templates/cpp/graph_traversal.cpp)

### Minimum Spanning Tree (Kruskal)
Find minimum-weight connected subgraph.

**Pattern:**
```cpp
sort(edges.begin(), edges.end());
for (auto [w, u, v] : edges) {
    if (find(u) != find(v)) {
        union_sets(u, v);
        total_weight += w;
    }
}
```

**See:** [templates/cpp/dsu.cpp](../templates/cpp/dsu.cpp)

## Common Pitfalls

- **Stack overflow**: Deep recursion on large graphs (use iterative DFS)
- **Missing edge cases**: Disconnected graphs, self-loops
- **Adjacency representation**: Choose correctly between adjacency list vs matrix
- **Dijkstra on negative weights**: Dijkstra fails with negative edges

**See:** [notes/pitfalls/graph-traversal-mistakes.md](../notes/pitfalls/graph-traversal-mistakes.md)

## Representative Problems

- Shortest path in unweighted grid (BFS)
- Weighted shortest path (Dijkstra)
- Course scheduling (topological sort)
- Network connectivity (DFS/DSU)
- Minimum cost to connect (MST)

**See:** [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)

## Related Patterns

- [Trees](trees.md) - Trees are acyclic connected graphs
- [Dynamic Programming](dynamic-programming.md) - Graph DP
- DSU template: [templates/cpp/dsu.cpp](../templates/cpp/dsu.cpp)
