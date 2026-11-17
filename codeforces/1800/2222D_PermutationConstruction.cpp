
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), prefix(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if (prefix[i] != prefix[j]) {
            return prefix[i] < prefix[j];
        }
        return i < j;
    });

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        p[idx[i]] = n - i;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << (i + 1 == n ? '\n' : ' ');
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
