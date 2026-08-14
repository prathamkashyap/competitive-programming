
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s;
    cin >> s;

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 6;
                q.push(v);
            }
        }
    }

    bool first = true;
    for (int node = 1; node <= n; node++) {
        if (node == s) {
            continue;
        }
        if (!first) {
            cout << ' ';
        }
        cout << dist[node];
        first = false;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
