#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n, k, z;
    cin >> n >> k >> z;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const ll NEG = -(1LL << 60);

    vector<ll> dp(z + 1, NEG);
    vector<ll> ndp(z + 1, NEG);

    // Initially at index 0 with no moves.
    dp[0] = a[0];

    for (int step = 0; step < k; step++) {
        fill(ndp.begin(), ndp.end(), NEG);

        for (int left = 0; left <= z; left++) {
            if (dp[left] == NEG) {
                continue;
            }

            // Current position after step moves.
            int pos = step - 2 * left;

            // Move right.
            if (pos + 1 < n) {
                ndp[left] = max(
                    ndp[left],
                    dp[left] + a[pos + 1]
                );
            }

            // Move left.
            if (left < z && pos > 0) {
                ndp[left + 1] = max(
                    ndp[left + 1],
                    dp[left] + a[pos - 1]
                );
            }
        }

        dp.swap(ndp);
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
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