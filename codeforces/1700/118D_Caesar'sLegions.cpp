#include <iostream>

using namespace std;

const int MOD = 100000000;

int dp[101][101][2][11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    if (n1 > 0) {
        dp[1][0][0][1] = 1;
    }

    if (n2 > 0) {
        dp[0][1][1][1] = 1;
    }

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {

            // Arrangements ending with footmen
            for (int len = 1; len <= k1; len++) {
                int ways = dp[i][j][0][len];

                if (ways == 0) {
                    continue;
                }

                // Add another footman
                if (i < n1 && len < k1) {
                    dp[i + 1][j][0][len + 1] =
                        (dp[i + 1][j][0][len + 1] + ways) % MOD;
                }

                // Add a horseman
                if (j < n2) {
                    dp[i][j + 1][1][1] =
                        (dp[i][j + 1][1][1] + ways) % MOD;
                }
            }

            // Arrangements ending with horsemen
            for (int len = 1; len <= k2; len++) {
                int ways = dp[i][j][1][len];

                if (ways == 0) {
                    continue;
                }

                // Add another horseman
                if (j < n2 && len < k2) {
                    dp[i][j + 1][1][len + 1] =
                        (dp[i][j + 1][1][len + 1] + ways) % MOD;
                }

                // Add a footman
                if (i < n1) {
                    dp[i + 1][j][0][1] =
                        (dp[i + 1][j][0][1] + ways) % MOD;
                }
            }
        }
    }

    int ans = 0;

    for (int len = 1; len <= k1; len++) {
        ans = (ans + dp[n1][n2][0][len]) % MOD;
    }

    for (int len = 1; len <= k2; len++) {
        ans = (ans + dp[n1][n2][1][len]) % MOD;
    }

    cout << ans << '\n';

    return 0;
}