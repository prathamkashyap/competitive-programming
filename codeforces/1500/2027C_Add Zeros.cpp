#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

using ll = long long;

unordered_map<ll, vector<ll>> graph;
unordered_map<ll, ll> dp;

ll dfs(ll len) {
    if (dp.count(len))
        return dp[len];

    ll best = len;

    if (graph.count(len)) {
        for (ll nxt : graph[len]) {
            best = max(best, dfs(nxt));
        }
    }

    return dp[len] = best;
}

void solve() {
    int n;
    cin >> n;

    graph.clear();
    dp.clear();

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;

        if (i == 1)
            continue;

        ll need = x + i - 1;
        ll nxt = need + (i - 1);

        graph[need].push_back(nxt);
    }

    cout << dfs(n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}