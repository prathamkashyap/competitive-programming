#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> diff(n + 1, 0);
    vector<pair<int, int>> intervals;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int k = 1; k <= n; k++) {
        for (int j = 0; j < a[k]; j++) {
            int l = j * k;
            int r = min(n - 1, (j + 1) * k - 1);

            intervals.push_back({l, r});
        }

        ll l = 1LL * a[k] * k;
        ll r = min(1LL * n - 1, 1LL * (a[k] + 1) * k - 1);

        if (l < n) {
            diff[l]++;

            if (r + 1 < n) {
                diff[r + 1]--;
            }
        }
    }

    vector<int> allowed;
    int blocked = 0;

    for (int i = 0; i < n; i++) {
        blocked += diff[i];

        if (blocked == 0) {
            allowed.push_back(i);
        }
    }

    vector<pair<int, int>> required;

    for (auto [l, r] : intervals) {
        int left = lower_bound(
            allowed.begin(), allowed.end(), l
        ) - allowed.begin();

        int right = upper_bound(
            allowed.begin(), allowed.end(), r
        ) - allowed.begin();

        if (left < right) {
            required.push_back({left + 1, right});
        }
    }

    sort(required.begin(), required.end(),
         [](const auto& x, const auto& y) {
             return x.second < y.second;
         });

    int m = allowed.size();

    vector<ll> dp(m + 1, 0);
    vector<ll> prefix(m + 1, 0);

    dp[0] = 1;
    prefix[0] = 1;

    int minLeft = 0;
    int maxLeft = 0;
    int j = 0;

    for (auto [l, r] : required) {
        maxLeft = max(maxLeft, l);
    }

    for (int i = 1; i <= m; i++) {
        while (j < (int)required.size() &&
               required[j].second < i) {
            minLeft = max(minLeft, required[j].first);
            j++;
        }

        if (minLeft == 0) {
            dp[i] = prefix[i - 1];
        } else {
            dp[i] = (
                prefix[i - 1] - prefix[minLeft - 1] + MOD
            ) % MOD;
        }

        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    }

    ll ans = 0;

    for (int i = maxLeft; i <= m; i++) {
        ans = (ans + dp[i]) % MOD;
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
