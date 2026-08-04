#include <iostream>
#include <unordered_map>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    unordered_map<ll, ll> freq;

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;

        ll key = x - i;

        ans += freq[key];
        freq[key]++;
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