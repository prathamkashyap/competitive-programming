#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);

    for (ll &x : a)
        cin >> x;

    ll answer = 0;
    ll currentMax = a[0];

    for (int i = 1; i < n; i++) {
        if ((a[i] > 0) == (currentMax > 0)) {
            currentMax = max(currentMax, a[i]);
        } else {
            answer += currentMax;
            currentMax = a[i];
        }
    }

    answer += currentMax;

    cout << answer << '\n';
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