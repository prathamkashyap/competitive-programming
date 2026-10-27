#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n + 1, 0);
    vector<int> depth(n + 1, 0);
    vector<int> subtree(n + 1, 1);
    vector<int> order;

    order.reserve(n);
    order.push_back(1);
    parent[1] = -1;

    for (int i = 0; i < static_cast<int>(order.size()); i++) {
        int u = order[i];

        for (int v : adj[u]) {
            if (v == parent[u]) {
                continue;
            }

            parent[v] = u;
            depth[v] = depth[u] + 1;
            order.push_back(v);
        }
    }

    for (int i = n - 1; i > 0; i--) {
        int u = order[i];
        subtree[parent[u]] += subtree[u];
    }

    vector<ll> score;
    score.reserve(n);

    for (int u = 1; u <= n; u++) {
        score.push_back(
            static_cast<ll>(depth[u]) - subtree[u] + 1
        );
    }

    sort(score.begin(), score.end(), greater<ll>());

    ll ans = 0;

    for (int i = 0; i < k; i++) {
        ans += score[i];
    }

    cout << ans << '\n';

    return 0;
}