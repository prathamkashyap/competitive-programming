#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    ll minSum = k * (k + 1) / 2;
    ll maxSum = k * (2 * n - k + 1) / 2;

    cout << (minSum <= x && x <= maxSum ? "YES" : "NO") << '\n';
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