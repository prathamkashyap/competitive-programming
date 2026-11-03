#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<array<int, 3>> edges(m);
    ll total = 0;

    for (auto& e : edges) {
        cin >> e[1] >> e[2] >> e[0];
        total += e[0];
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    vector<ll> weights;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            weights.push_back(w);
        }
    }

    int c = n - (int)weights.size();

    ll mstSum = accumulate(weights.begin(), weights.end(), 0LL);
    ll base = total - mstSum;

    reverse(weights.begin(), weights.end());

    int k = weights.size();

    vector<ll> pref(k + 1, 0);

    for (int i = 0; i < k; i++) {
        pref[i + 1] = pref[i] + weights[i];
    }

    while (q--) {
        ll x;
        cin >> x;

        int l = 0, r = k;

        while (l < r) {
            int mid = (l + r + 1) / 2;

            if (weights[mid - 1] > x * (c + mid - 1LL)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        ll removed = l;
        ll cables = c - 1LL + removed;

        ll cost = x * cables * (cables + 1) / 2;

        ll ans = base + pref[removed] - cost;

        cout << ans << (q ? ' ' : '\n');
    }
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