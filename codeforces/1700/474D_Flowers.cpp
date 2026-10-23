#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;

    vector<int> dp(MAXN + 1, 0);
    vector<int> prefix(MAXN + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= MAXN; i++) {
        dp[i] = dp[i - 1];

        if (i >= k) {
            dp[i] = (dp[i] + dp[i - k]) % MOD;
        }

        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    }

    while (t--) {
        int a, b;
        cin >> a >> b;

        int ans = (prefix[b] - prefix[a - 1] + MOD) % MOD;
        cout << ans << '\n';
    }

    return 0;
}