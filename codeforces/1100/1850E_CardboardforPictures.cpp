#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll c;

        cin >> n >> c;

        vector<ll> s(n);

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        ll low = 1;
        ll high = 1000000000LL;
        ll answer = 0;

        while (low <= high) {
            ll w = low + (high - low) / 2;

            ll total = 0;

            for (int i = 0; i < n; i++) {
                ll side = s[i] + 2 * w;

                total += side * side;

                if (total > c) {
                    break;
                }
            }

            if (total == c) {
                answer = w;
                break;
            }

            if (total < c) {
                low = w + 1;
            } else {
                high = w - 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}