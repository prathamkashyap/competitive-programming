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
        int n;
        long long h;
        cin >> n >> h;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long low = 1;
        long long high = h;

        while (low < high) {
            long long k = low + (high - low) / 2;

            long long damage = k;

            for (int i = 1; i < n; i++) {
                damage += min(k, a[i] - a[i - 1]);
            }

            if (damage >= h) {
                high = k;
            } else {
                low = k + 1;
            }
        }

        cout << low << '\n';
    }

    return 0;
}