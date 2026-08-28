#include <iostream>
#include <vector>
#include <numeric>

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

        long long evenGcd = 0;
        long long oddGcd = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenGcd = gcd(evenGcd, a[i]);
            } else {
                oddGcd = gcd(oddGcd, a[i]);
            }
        }

        bool evenPossible = true;

        for (int i = 1; i < n; i += 2) {
            if (a[i] % evenGcd == 0) {
                evenPossible = false;
                break;
            }
        }

        if (evenPossible) {
            cout << evenGcd << '\n';
            continue;
        }

        bool oddPossible = true;

        for (int i = 0; i < n; i += 2) {
            if (a[i] % oddGcd == 0) {
                oddPossible = false;
                break;
            }
        }

        if (oddPossible) {
            cout << oddGcd << '\n';
        } else {
            cout << 0 << '\n';
        }
    }

    return 0;
}