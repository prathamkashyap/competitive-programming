#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = a[0];
        long long current = a[0];

        for (int i = 1; i < n; i++) {

            // & 1 correctly identifies odd/even even for negative numbers
            if ((a[i] & 1LL) != (a[i - 1] & 1LL)) {
                current = max(a[i], current + a[i]);
            } else {
                current = a[i];
            }

            ans = max(ans, current);
        }

        cout << ans << '\n';
    }

    return 0;
}