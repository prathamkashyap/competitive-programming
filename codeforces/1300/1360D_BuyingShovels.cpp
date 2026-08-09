#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll best = 1;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i != 0)
            continue;

        ll d1 = i;
        ll d2 = n / i;

        if (d1 <= k)
            best = max(best, d1);

        if (d2 <= k)
            best = max(best, d2);
    }

    cout << n / best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}