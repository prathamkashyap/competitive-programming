#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

bool canReach(const vector<pair<ll, ll>>& segments, ll k) {
    ll L = 0, R = 0;

    for (const auto& segment : segments) {
        ll l = segment.first;
        ll r = segment.second;

        L = max(L - k, l);
        R = min(R + k, r);

        if (L > R) {
            return false;
        }
    }

    return true;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> segments(n);

    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    ll low = 0, high = 1000000000LL;

    while (low < high) {
        ll mid = low + (high - low) / 2;

        if (canReach(segments, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';
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