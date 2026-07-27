#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll ans = 0;

        for (int b = 1; b <= n; b++) {
            ll cnt = n / b;
            ans += cnt * cnt;
        }

        cout << ans << '\n';
    }

    return 0;
}