#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long divisor = 1;

        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                divisor = n / i;
                break;
            }
        }

        cout << divisor << " " << n - divisor << '\n';
    }

    return 0;
}