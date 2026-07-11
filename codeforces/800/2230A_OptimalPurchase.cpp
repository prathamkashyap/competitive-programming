#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int64 n, a, b;
        cin >> n >> a >> b;

        if (b >= 3 * a) {
            cout << n * a << '\n';
            continue;
        }

        int64 groups = n / 3;
        int64 rem = n % 3;

        cout << groups * b + min(rem * a, b) << '\n';
    }

    return 0;
}