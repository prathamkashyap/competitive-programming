#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, x;
        cin >> n >> x;

        vector<long long> a(n);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }

        if (total % x != 0) {
            cout << n << '\n';
            continue;
        }

        int first = -1;
        int last = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] % x != 0) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }

        if (first == -1) {
            cout << -1 << '\n';
        } else {
            cout << max(n - first - 1, last) << '\n';
        }
    }

    return 0;
}