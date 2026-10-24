# 🌲 Trees Advanced 🧠

Advanced tree queries and algorithms I use for tree problems.

---

## 🔍 LCA (Lowest Common Ancestor)

Binary lifting preprocess in O(n log n), queries in O(log n).

```cpp
const int LOGN = 20;
int up[MAXN][LOGN];
int depth[MAXN];

void dfs(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;
    for (int i = 1; i < LOGN; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v != p) dfs(v, u, d + 1);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
```

---

## 📊 Subtree Queries

Euler tour flattens tree to array for subtree range queries.

```cpp
vector<int> euler, tin, tout;
int timer = 0;

void dfs_euler(int u, int p) {
    tin[u] = timer++;
    euler.push_back(u);
    for (int v : adj[u]) {
        if (v != p) dfs_euler(v, u);
    }
    tout[u] = timer++;
    euler.push_back(u);
}

// Subtree of u is range [tin[u], tout[u]]
```

---

## 🦘 Binary Lifting

Jump 2^k ancestors for fast LCA and path queries.

```cpp
int jump(int u, int k) {
    for (int i = 0; i < LOGN; i++) {
        if (k & (1 << i)) u = up[u][i];
    }
    return u;
}
```

---

## 🎯 When to Use

| 🎯 Problem | 🧩 Algorithm | ⏱️ Complexity |
| :--- | :--- | :--- |
| Common ancestor queries | LCA (binary lifting) | O(n log n) preprocess, O(log n) query |
| Subtree queries | Euler tour + prefix sums | O(n) preprocess, O(1) query |
| K-th ancestor | Binary lifting | O(n log n) preprocess, O(log n) query |
| Path between nodes | LCA + distance | O(log n) |

---

## 💡 Quick Tips

- Use binary lifting for any ancestor-related queries
- Euler tour transforms subtree queries to range queries
- Distance between nodes = depth[u] + depth[v] - 2*depth[lca(u,v)]
- Set LOGN = ceil(log2(max nodes)) + 1

---

## 📚 Related

- Template: [`lca.cpp`](../templates/cpp/lca.cpp) 🌲
- Basic trees: [graphs_and_trees.md](graphs_and_trees.md) 📖

---

[← Back to Notes](../README.md)
