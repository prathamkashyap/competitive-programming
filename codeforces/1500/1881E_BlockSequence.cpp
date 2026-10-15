#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> dp(N + 1, 0);

    for (int i = N - 1; i >= 0; i--) {
        dp[i] = 1 + dp[i + 1];

        if (i + a[i] < N) {
            dp[i] = min(dp[i], dp[i + a[i] + 1]);
        }
    }

    cout << dp[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}