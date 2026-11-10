#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll x, y;
    cin >> x >> y;

    ll k = 0;

    while ((k + 1) * (k + 2) / 2 <= x + y) {
        k++;
    }

    ll total = k * (k + 1) / 2;

    ll low = max(0LL, total - y);
    ll high = min(x, total);

    ll target = (total + x - y) / 2;

    target = max(low, min(high, target));

    ll best = target;

    auto distance = [&](ll p) -> ll {
        ll q = total - p;
        return (x - p) * (x - p) + (y - q) * (y - q);
    };

    if (target + 1 <= high &&
        distance(target + 1) < distance(best)) {
        best = target + 1;
    }

    string ans(k, 'Y');

    for (int i = 0; i < k; i++) {
        ll contribution = k - i;

        if (best >= contribution) {
            ans[i] = 'X';
            best -= contribution;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TestsNumT;
    cin >> TestsNumT;

    while (TestsNumT--) {
        solve();
    }

    return 0;
}