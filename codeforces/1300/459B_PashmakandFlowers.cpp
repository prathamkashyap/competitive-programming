#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll mn = *min_element(a.begin(), a.end());
    ll mx = *max_element(a.begin(), a.end());

    if (mn == mx) {
        cout << 0 << " " << 1LL * n * (n - 1) / 2 << '\n';
        return 0;
    }

    ll cntMin = 0, cntMax = 0;

    for (ll x : a) {
        if (x == mn) cntMin++;
        if (x == mx) cntMax++;
    }

    cout << mx - mn << " " << cntMin * cntMax << '\n';

    return 0;
}