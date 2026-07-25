#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int INF = INT_MAX;
    vector<int> dp(8, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int cost;
        string s;
        cin >> cost >> s;

        int mask = 0;
        for (char c : s) {
            if (c == 'A') mask |= 1;
            else if (c == 'B') mask |= 2;
            else if (c == 'C') mask |= 4;
        }

        vector<int> ndp = dp;

        for (int m = 0; m < 8; m++) {
            if (dp[m] == INF) continue;
            ndp[m | mask] = min(ndp[m | mask], dp[m] + cost);
        }

        dp = ndp;
    }

    if (dp[7] == INF)
        cout << -1 << '\n';
    else
        cout << dp[7] << '\n';

    return 0;
}