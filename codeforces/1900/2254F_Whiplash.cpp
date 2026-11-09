#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int xr = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xr ^= a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        xr ^= b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b) {
        cout << "YES\n";
        return;
    }

    auto it = lower_bound(a.begin(), a.end(), xr);

    if (it == a.end() || *it != xr) {
        cout << "NO\n";
        return;
    }

    int pos = it - a.begin();

    for (int i = 0; i < n; i++) {
        if (i != pos) {
            a[i] ^= xr;
        }
    }

    sort(a.begin(), a.end());

    cout << (a == b ? "YES\n" : "NO\n");
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