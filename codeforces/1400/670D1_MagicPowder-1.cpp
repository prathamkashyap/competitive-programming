#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ll low = 0;
    ll high = 2000000000LL;

    while (low < high) {
        ll mid = low + (high - low + 1) / 2;
        ll needed = 0;

        for (int i = 0; i < n; i++) {
            ll required = mid * a[i];

            if (required > b[i]) {
                needed += required - b[i];
            }

            if (needed > k) {
                break;
            }
        }

        if (needed <= k) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}