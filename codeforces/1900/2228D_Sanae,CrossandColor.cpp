
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    vector<int> present(n + 2, 0);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        present[points[i].second] = 1;
    }

    for (int i = 1; i <= n; i++) {
        present[i] += present[i - 1];
    }

    sort(points.begin(), points.end());

    vector<int> suffixMin(n + 1, INT_MAX);
    vector<int> suffixMax(n + 1, INT_MIN);

    for (int i = n - 1; i >= 0; i--) {
        suffixMin[i] = min(suffixMin[i + 1], points[i].second);
        suffixMax[i] = max(suffixMax[i + 1], points[i].second);
    }

    int leftMin = INT_MAX;
    int leftMax = INT_MIN;

    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        int x = points[i].first;
        int y = points[i].second;

        leftMin = min(leftMin, y);
        leftMax = max(leftMax, y);

        if (points[i + 1].first == x) {
            continue;
        }

        int rightMin = suffixMin[i + 1];
        int rightMax = suffixMax[i + 1];

        int low = max(leftMin, rightMin);
        int high = min(leftMax, rightMax);

        if (low < high) {
            ans += present[high] - present[low];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
