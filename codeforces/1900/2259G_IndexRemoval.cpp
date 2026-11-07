#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> adjusted(n);
    vector<ll> prefix(n + 1, 0);
    vector<ll> ans(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        adjusted[i] = a[i] - 1LL * i * k;
        prefix[i + 1] = prefix[i] + a[i];
    }

    for (int i = 1; i < n - 1; i++) {
        ll target = a[i - 1] - 1LL * i * k;

        int left = i + 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (adjusted[mid] <= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        ll count = left - i - 1;

        ll sum = prefix[left] - prefix[i + 1];

        ll allowed = count * a[i - 1]
                   + k * count * (count + 1) / 2;

        ans[i] = sum - allowed;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
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