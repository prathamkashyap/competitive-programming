# 🌲 Graph Theory & Tree Algorithms

## 1. Algorithm Selection Guide

| Problem Type | Graph Properties | Best Algorithm | Time Complexity |
| :--- | :--- | :--- | :---: |
| **Shortest Path (Unweighted)** | Any | Breadth-First Search (BFS) | $O(V + E)$ |
| **Shortest Path (Weighted, Non-negative)** | Non-negative edge weights | Dijkstra's Algorithm | $O((V + E) \log V)$ |
| **Shortest Path (Negative weights)** | No negative cycles | Bellman-Ford Algorithm | $O(V \cdot E)$ |
| **All-Pairs Shortest Path** | Small $V \le 500$ | Floyd-Warshall Algorithm | $O(V^3)$ |
| **Minimum Spanning Tree (MST)** | Undirected | Kruskal's (DSU) / Prim's | $O(E \log E)$ |
| **Cycle Detection (Directed)** | Directed Graph | DFS (3 colors: 0/1/2) | $O(V + E)$ |
| **Topological Sort** | Directed Acyclic Graph (DAG) | Kahn's (In-degree) / DFS | $O(V + E)$ |
| **Lowest Common Ancestor (LCA)** | Tree | Binary Lifting | $O(N \log N)$ build, $O(\log N)$ query |

---

## 2. Dijkstra's Algorithm Template

```cpp
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

vector<long long> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& adj) {
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            long long weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

---

[← Back to Notes](README.md)
