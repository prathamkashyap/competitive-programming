#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k >= 3) {
        cout << 0 << '\n';
        return;
    }

    sort(a.begin(), a.end());

    long long ans = a[0];

    for (int i = 1; i < n; i++) {
        ans = min(ans, a[i] - a[i - 1]);
    }

    if (k == 1) {
        cout << ans << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long d = a[j] - a[i];
            ans = min(ans, d);

            auto it = lower_bound(a.begin(), a.end(), d);

            if (it != a.end()) {
                ans = min(ans, abs(*it - d));
            }

            if (it != a.begin()) {
                --it;
                ans = min(ans, abs(*it - d));
            }

            if (ans == 0) {
                cout << 0 << '\n';
                return;
            }
        }
    }

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