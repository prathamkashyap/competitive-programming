#include <iostream>
#include <cmath>
using namespace std;

bool isCube(long long x) {
    long long b = cbrt(x);

    // Correct possible floating-point rounding
    while ((b + 1) * (b + 1) * (b + 1) <= x) {
        b++;
    }

    while (b * b * b > x) {
        b--;
    }

    return b * b * b == x;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        bool found = false;

        for (long long a = 1; a * a * a < x; a++) {
            long long remaining = x - a * a * a;

            if (isCube(remaining)) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}