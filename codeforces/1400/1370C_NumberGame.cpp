#include <iostream>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) {
        return false;
    }

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

string solve(long long n) {
    if (n == 1) {
        return "FastestFinger";
    }

    if (n == 2 || n % 2 == 1) {
        return "Ashishgup";
    }

    if ((n & (n - 1)) == 0) {
        return "FastestFinger";
    }

    if (n % 4 == 2 && isPrime(n / 2)) {
        return "FastestFinger";
    }

    return "Ashishgup";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n;
        cin >> n;

        cout << solve(n) << '\n';
    }

    return 0;
}