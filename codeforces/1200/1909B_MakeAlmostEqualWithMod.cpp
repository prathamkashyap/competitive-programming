#include <iostream>
#include <vector>
#include <set>

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

        long long x = 2;

        while (true) {
            set<long long> remainders;

            for (int i = 0; i < n; i++) {
                remainders.insert(a[i] % x);
            }

            if (remainders.size() == 2) {
                cout << x << '\n';
                break;
            }

            x *= 2;
        }
    }

    return 0;
}