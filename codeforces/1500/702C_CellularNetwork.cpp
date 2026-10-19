#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> cities(n), towers(m);

    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    sort(cities.begin(), cities.end());
    sort(towers.begin(), towers.end());

    ll ans = 0;

    for (ll city : cities) {
        auto it = lower_bound(towers.begin(), towers.end(), city);

        ll dist = (1LL << 62);

        if (it != towers.end()) {
            dist = min(dist, *it - city);
        }

        if (it != towers.begin()) {
            dist = min(dist, city - *prev(it));
        }

        ans = max(ans, dist);
    }

    cout << ans << '\n';

    return 0;
}