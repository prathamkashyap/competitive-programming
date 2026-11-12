
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> a(n), c(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i < n; i++) {
        if (c[i] < c[i - 1]) {
            cout << "No\n";
            return;
        }
    }

    ll prefix = 0;
    bool possible = true;

    int i = 0;

    while (i < n && possible) {
        if (s[i] == '1') {
            prefix += a[i];

            if (i == 0 || c[i] > c[i - 1]) {
                if (prefix != c[i]) {
                    possible = false;
                }
            } else if (prefix > c[i]) {
                possible = false;
            }

            i++;
            continue;
        }

        int j = i;
        ll delta = 0;
        ll upper = LLONG_MAX;
        ll forced = 0;
        bool hasForced = false;

        while (i < n && (i == j || s[i] == '1')) {
            if (i > j) {
                delta += a[i];
            }

            ll bound = c[i] - delta;
            upper = min(upper, bound);

            if (i == 0 || c[i] > c[i - 1]) {
                if (!hasForced) {
                    forced = bound;
                    hasForced = true;
                } else if (forced != bound) {
                    possible = false;
                }
            }

            i++;
        }

        if (!possible) {
            break;
        }

        ll target = hasForced ? forced : upper;

        if (target > upper) {
            possible = false;
            break;
        }

        a[j] = target - prefix;
        prefix = target + delta;
    }

    if (!possible) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
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
