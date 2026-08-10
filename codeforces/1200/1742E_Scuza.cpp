#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> prefix(n + 1, 0);
    vector<ll> maxStep(n);

    ll currentMax = 0;

    for (int i = 0; i < n; i++) {
        ll height;
        cin >> height;

        prefix[i + 1] = prefix[i] + height;
        currentMax = max(currentMax, height);
        maxStep[i] = currentMax;
    }

    while (q--) {
        ll k;
        cin >> k;

        int steps = upper_bound(maxStep.begin(), maxStep.end(), k)
                    - maxStep.begin();

        cout << prefix[steps] << ' ';
    }

    cout << '\n';
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