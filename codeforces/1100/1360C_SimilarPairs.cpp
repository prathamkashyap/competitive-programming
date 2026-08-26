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

        vector<int> a(n);

        int odd = 0;
        int even = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        // Case 1:
        // Both parity counts are even.
        if (odd % 2 == 0 && even % 2 == 0) {
            cout << "YES\n";
            continue;
        }

        // Case 2:
        // Both counts are odd, so we need one
        // odd-even pair whose difference is exactly 1.
        bool found = false;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(a[i] - a[j]) == 1) {
                    found = true;
                    break;
                }
            }

            if (found)
                break;
        }

        if (found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}