#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long sum = 0;
        long long mx = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;

            sum += x;
            mx = max(mx, x);

            if (sum == 2 * mx) {
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}