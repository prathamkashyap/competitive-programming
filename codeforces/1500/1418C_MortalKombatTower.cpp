#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(N + 2, vector<int>(2, 0));

    for (int i = N - 1; i >= 0; i--) {
        // Your turn
        dp[i][0] = a[i] + dp[i + 1][1];

        if (i + 1 < N) {
            dp[i][0] = min(
                dp[i][0],
                a[i] + a[i + 1] + dp[i + 2][1]
            );
        }

        // Friend's turn
        dp[i][1] = dp[i + 1][0];

        if (i + 1 < N) {
            dp[i][1] = min(
                dp[i][1],
                dp[i + 2][0]
            );
        }
    }

    return dp[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << '\n';
    }

    return 0;
}