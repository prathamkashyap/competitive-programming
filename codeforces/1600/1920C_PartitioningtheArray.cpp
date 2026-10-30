#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for (int k = 1; k <= n; k++) {
        if (n % k != 0) {
            continue;
        }

        int g = 0;

        for (int i = 0; i + k < n; i++) {
            g = gcd(g, abs(a[i] - a[i + k]));

            if (g == 1) {
                break;
            }
        }

        if (g != 1) {
            ans++;
        }
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