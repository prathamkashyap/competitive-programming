# Trees Pattern

## When to Recognize

Problems involving:
- Hierarchical structures
- Parent-child relationships
- Tree properties (diameter, height, LCA)
- Path queries on trees
- Tree traversal and modification

## Core Idea

Leverage tree properties: single path between any two nodes, recursive structure, parent-child relationships. Apply DFS/BFS with careful state tracking.

## Common Complexity

- **Single traversal**: $O(N)$
- **Multiple queries without preprocessing**: $O(N)$ per query
- **With preprocessing (LCA, heavy-light)**: $O(\log N)$ per query

## Common Variations

### Tree Traversal
Visit all nodes via DFS or BFS.

**Pattern:**
```cpp
void dfs(int node, int parent) {
    // process node
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
        }
    }
}
```

### Tree Diameter
Longest path between any two nodes.

**Pattern:**
```cpp
int bfs_farthest(int start) {
    // BFS from start, return farthest node and distance
}
pair<int, int> first = bfs_farthest(1);
pair<int, int> second = bfs_farthest(first.first);
int diameter = second.second;
```

### Lowest Common Ancestor (LCA)
Find deepest common ancestor of two nodes.

**Pattern:**
```cpp
// Binary lifting: preprocess ancestors at powers of 2
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    // lift u to same depth as v
    // lift both together
}
```

## Common Pitfalls

- **Stack overflow**: Deep recursion on skewed trees (use iterative DFS)
- **Parent confusion**: Losing track of parent in undirected trees
- **Root assumption**: Problems may not specify root
- **Off-by-one in depth**: Depth vs number of edges

**See:** [notes/graphs_and_trees.md](../notes/graphs_and_trees.md)

## Representative Problems

- Tree diameter
- LCA queries
- Subtree queries
- Tree DP (maximum independent set, etc.)

## Related Patterns

- [Graphs](graphs.md) - Trees are acyclic connected graphs
- [Dynamic Programming](dynamic-programming.md) - Tree DP
- [Recursion](recursion-backtracking.md) - Tree traversal is recursive
