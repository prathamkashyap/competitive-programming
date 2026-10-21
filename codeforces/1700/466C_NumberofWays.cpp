#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    ll total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }

    if (total % 3 != 0) {
        cout << 0 << '\n';
        return;
    }

    ll target = total / 3;
    ll prefix = 0;
    ll cnt = 0;
    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        prefix += a[i];

        if (prefix == 2 * target) {
            ans += cnt;
        }

        if (prefix == target) {
            cnt++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}