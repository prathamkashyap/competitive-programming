#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    priority_queue<pair<int, int>> pq;

    pq.push({n, 0});

    for (int i = 1; i <= n; i++) {
        auto [len, negL] = pq.top();
        pq.pop();

        int l = -negL;
        int r = l + len - 1;
        int mid = (l + r) / 2;

        a[mid] = i;

        if (mid > l) {
            pq.push({mid - l, -l});
        }

        if (mid < r) {
            pq.push({r - mid, -(mid + 1)});
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
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