#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        for (long long sum = 3; sum <= n; sum = 2 * sum + 1) {
            if (n % sum == 0) {
                cout << n / sum << '\n';
                break;
            }
        }
    }

    return 0;
}