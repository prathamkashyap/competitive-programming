#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    int m = static_cast<int>(vals.size());

    vector<int> dp(m, 0);
    vector<int> endAt(m, -1);
    vector<int> parent(n, -1);

    int bestLen = 0;
    int bestEnd = -1;

    for (int i = 0; i < n; i++) {
        int idx = lower_bound(vals.begin(), vals.end(), a[i])
                - vals.begin();

        int len = 1;
        int prev = -1;

        auto it = lower_bound(vals.begin(), vals.end(), a[i] - 1);

        if (it != vals.end() && *it == a[i] - 1) {
            int pred = it - vals.begin();

            if (dp[pred] > 0) {
                len = dp[pred] + 1;
                prev = endAt[pred];
            }
        }

        if (len > dp[idx]) {
            dp[idx] = len;
            endAt[idx] = i;
            parent[i] = prev;
        }

        if (dp[idx] > bestLen) {
            bestLen = dp[idx];
            bestEnd = endAt[idx];
        }
    }

    vector<int> answer;

    while (bestEnd != -1) {
        answer.push_back(bestEnd + 1);
        bestEnd = parent[bestEnd];
    }

    reverse(answer.begin(), answer.end());

    cout << bestLen << '\n';

    for (int i = 0; i < bestLen; i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }

    cout << '\n';

    return 0;
}