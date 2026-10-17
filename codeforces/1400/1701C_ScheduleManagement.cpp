#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFinish(const vector<int>& cnt, int n, int T) {
    long long need = 0;
    long long available = 0;

    for (int i = 0; i < n; i++) {
        if (cnt[i] > T) {
            need += cnt[i] - T;
        } else {
            available += (T - cnt[i]) / 2;
        }
    }

    return available >= need;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(n, 0);

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cnt[a - 1]++;
    }

    int low = 0, high = m;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (canFinish(cnt, n, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';
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