#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> graph;
vector<bool> visited;

int dfs(int node) {
    visited[node] = true;
    int cnt = 1;

    for (int nxt : graph[node]) {
        if (!visited[nxt])
            cnt += dfs(nxt);
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> capitals(k);

    for (int i = 0; i < k; i++) {
        cin >> capitals[i];
        capitals[i]--;
    }

    graph.resize(n);
    visited.assign(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> componentSizes;
    int largest = 0;

    for (int c : capitals) {
        int sz = dfs(c);
        componentSizes.push_back(sz);
        largest = max(largest, sz);
    }

    int extra = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            extra += dfs(i);
        }
    }

    ll ans = 0;
    bool used = false;

    for (int sz : componentSizes) {
        if (!used && sz == largest) {
            sz += extra;
            used = true;
        }

        ans += 1LL * sz * (sz - 1) / 2;
    }

    cout << ans - m << '\n';

    return 0;
}