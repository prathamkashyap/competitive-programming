#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll s, k, m;
        cin >> s >> k >> m;

        ll flips = m / k;
        ll elapsed = m % k;

        ll rem;

        if (flips == 0) {
            rem = s;
        } else if (s <= k) {
            rem = s;
        } else {
            rem = (flips % 2 == 1) ? k : s;
        }

        cout << max(0LL, rem - elapsed) << '\n';
    }

    return 0;
}