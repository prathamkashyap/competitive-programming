#include <iostream>
using namespace std;

bool isPrime(long long x) {
    if (x < 2) {
        return false;
    }

    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long d;
        cin >> d;

        long long p = d + 1;

        while (!isPrime(p)) {
            p++;
        }

        long long q = p + d;

        while (!isPrime(q)) {
            q++;
        }

        cout << p * q << '\n';
    }

    return 0;
}