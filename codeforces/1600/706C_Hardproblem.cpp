#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> cost(n);
    vector<string> s(n);

    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    const ll INF = 4e18;

    vector<vector<ll>> dp(n, vector<ll>(2, INF));

    dp[0][0] = 0;
    dp[0][1] = cost[0];

    string prev = s[0];
    reverse(prev.begin(), prev.end());

    for (int i = 1; i < n; i++) {
        string curr = s[i];
        string rev = curr;
        reverse(rev.begin(), rev.end());

        if (s[i] >= s[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }

        if (s[i] >= prev) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }

        if (rev >= s[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + cost[i]);
        }

        if (rev >= prev) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);
        }

        prev = rev;
    }

    ll ans = min(dp[n - 1][0], dp[n - 1][1]);

    cout << (ans >= INF ? -1 : ans) << '\n';

    return 0;
}