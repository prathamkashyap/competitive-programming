#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        int xr = 0;
        int nonZero = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            xr ^= a[i];

            if (a[i] != 0)
                nonZero++;
        }

        if (nonZero <= 1) {
            cout << 0 << '\n';
            continue;
        }

        if (xr == 0) {
            cout << 1 << '\n';
            continue;
        }

        int highestBit = 31 - __builtin_clz(xr);

        int answer = 0;

        for (int x : a) {
            if ((x >> highestBit) & 1)
                answer++;
        }

        cout << answer % MOD << '\n';
    }
}