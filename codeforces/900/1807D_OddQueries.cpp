#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }

    while (q--) {
        int l, r;
        ll k;
        cin >> l >> r >> k;

        ll sum = prefix[n] - (prefix[r] - prefix[l - 1])
                 + (r - l + 1LL) * k;

        cout << (sum % 2 ? "YES" : "NO") << '\n';
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