#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        long long sticksNeeded = k * y + k - 1;
        long long trades = (sticksNeeded + x - 2) / (x - 1);

        cout << trades + k << '\n';
    }

    return 0;
}