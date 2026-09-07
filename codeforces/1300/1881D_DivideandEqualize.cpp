#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        map<long long, long long> factors;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            long long x = a[i];

            for (long long p = 2; p * p <= x; p++) {
                while (x % p == 0) {
                    factors[p]++;
                    x /= p;
                }
            }

            if (x > 1) {
                factors[x]++;
            }
        }

        bool possible = true;

        for (const auto &entry : factors) {
            if (entry.second % n != 0) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}