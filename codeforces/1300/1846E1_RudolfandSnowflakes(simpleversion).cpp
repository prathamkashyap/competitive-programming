#include <iostream>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    for (ll k = 2; k * k <= n; k++) {
        ll sum = 1 + k;
        ll term = k;

        while (sum < n) {
            term *= k;
            sum += term;
        }

        if (sum == n) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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