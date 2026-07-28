#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll ans;
vector<vector<int>> graph;

int dfs(int u, int p) {
    int mx1 = -1;
    int mx2 = -1;

    for (int v : graph[u]) {
        if (v == p) continue;

        int d = dfs(v, u) + 1;

        if (d > mx1) {
            mx2 = mx1;
            mx1 = d;
        } else if (d > mx2) {
            mx2 = d;
        }
    }

    if (mx2 == -1)
        ans += 1;
    else
        ans += mx2 + 1;

    return max(mx1, 0);
}

void solve() {
    int n;
    cin >> n;

    graph.assign(n + 1, {});

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        graph[p].push_back(i);
    }

    ans = 0;
    dfs(1, 0);

    cout << ans << '\n';
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