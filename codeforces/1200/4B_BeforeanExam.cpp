#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, sumTime;
    cin >> d >> sumTime;

    vector<int> low(d), high(d), ans(d);

    int minSum = 0;
    int maxSum = 0;

    for (int i = 0; i < d; i++) {
        cin >> low[i] >> high[i];

        minSum += low[i];
        maxSum += high[i];

        ans[i] = low[i];
    }

    if (sumTime < minSum || sumTime > maxSum) {
        cout << "NO\n";
        return 0;
    }

    int remaining = sumTime - minSum;

    for (int i = 0; i < d && remaining > 0; i++) {
        int extra = min(remaining, high[i] - low[i]);

        ans[i] += extra;
        remaining -= extra;
    }

    cout << "YES\n";

    for (int i = 0; i < d; i++) {
        cout << ans[i] << " ";
    }

    cout << '\n';

    return 0;
}