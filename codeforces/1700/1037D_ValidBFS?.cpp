#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> order(n), pos(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> order[i];
        pos[order[i]] = i;
    }

    if (order[0] != 1) {
        cout << "No\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(),
             [&](int a, int b) {
                 return pos[a] < pos[b];
             });
    }

    vector<int> bfs;
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        bfs.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    cout << (bfs == order ? "Yes\n" : "No\n");

    return 0;
}