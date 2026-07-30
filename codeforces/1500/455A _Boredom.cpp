#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    const int MAX = 100000;

    vector<ll> points(MAX + 1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        points[x] += x;
    }

    vector<ll> dp(MAX + 1, 0);

    dp[1] = points[1];

    for (int i = 2; i <= MAX; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
    }

    cout << dp[MAX] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}