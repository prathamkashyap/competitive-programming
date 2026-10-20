#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

using ll = long long;

class FenwickTree {
    int n;
    vector<int> bit;

public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    void update(int i, int value) {
        while (i <= n) {
            bit[i] += value;
            i += i & -i;
        }
    }

    int query(int i) const {
        int sum = 0;

        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }

        return sum;
    }
};

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    vector<int> rights(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        rights[i] = a[i].second;
    }

    sort(a.begin(), a.end());

    sort(rights.begin(), rights.end());
    rights.erase(unique(rights.begin(), rights.end()), rights.end());

    FenwickTree bit(static_cast<int>(rights.size()));

    ll ans = 0;
    int seen = 0;

    for (const auto& p : a) {
        int rank = static_cast<int>(
            lower_bound(rights.begin(), rights.end(), p.second)
            - rights.begin()
        ) + 1;

        // Previously seen right endpoints greater than p.second.
        ans += seen - bit.query(rank);

        bit.update(rank, 1);
        seen++;
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