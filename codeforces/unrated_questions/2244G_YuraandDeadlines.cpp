#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int idx, ll val) {
        while (idx <= n) {
            bit[idx] = max(bit[idx], val);
            idx += idx & -idx;
        }
    }
    ll query(int idx) {
        ll res = 0;
        while (idx > 0) {
            res = max(res, bit[idx]);
            idx -= idx & -idx;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<vector<int>> bucket(n + 2);
        vector<ll> dp(n + 1, 0);
        Fenwick fw(n);
        ll ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j : bucket[i]) fw.update(j, dp[j]);

            int lim = i - a[i] - 1;
            ll best = 0;
            if (lim > 0) best = fw.query(lim);

            dp[i] = best + a[i];
            ans = max(ans, dp[i]);

            long long t = 1LL * i + a[i] + 1;
            if (t <= n) bucket[t].push_back(i);
        }

        cout << ans << '\n';
    }

    return 0;
}