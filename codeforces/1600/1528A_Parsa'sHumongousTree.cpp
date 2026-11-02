#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> l(n + 1), r(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> order;

    order.push_back(1);
    parent[1] = -1;

    for (int i = 0; i < (int)order.size(); i++) {
        int u = order[i];

        for (int v : adj[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                order.push_back(v);
            }
        }
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];

        for (int v : adj[u]) {
            if (v == parent[u]) continue;

            dp[u][0] += max(
                dp[v][0] + abs(l[u] - l[v]),
                dp[v][1] + abs(l[u] - r[v])
            );

            dp[u][1] += max(
                dp[v][0] + abs(r[u] - l[v]),
                dp[v][1] + abs(r[u] - r[v])
            );
        }
    }

    cout << max(dp[1][0], dp[1][1]) << '\n';
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