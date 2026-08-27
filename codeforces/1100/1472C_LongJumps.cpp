#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> dp(n, 0);

        // Process from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Score obtained by visiting this position
            dp[i] = a[i];

            int next = i + a[i];

            // If the next position is inside the array,
            // add the best score obtainable from there.
            if (next < n) {
                dp[i] += dp[next];
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }

    return 0;
}