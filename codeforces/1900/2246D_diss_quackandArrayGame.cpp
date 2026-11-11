
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXA = 200000;

vector<int> cost(MAXA + 1);

void precompute() {
    for (int i = 1; i <= MAXA; i++) {
        if (i & 1) {
            cost[i] = cost[i - 1] + 1;
        } else {
            cost[i] = cost[i / 2] + 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += cost[a[i]];
    }

    for (int p = 1; p <= 17; p++) {
        int step = 1 << p;
        ll total = p;

        for (int x : a) {
            int add = (step - x % step) % step;
            int base = (x + add) / step;

            int best = INT_MAX;

            for (int extra = 0; extra <= 64 / step; extra++) {
                int value = base + extra;
                int moves = extra * step + cost[value];

                best = min(best, moves);
            }

            total += add + best;

            if (total >= ans) {
                break;
            }
        }

        ans = min(ans, total);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
