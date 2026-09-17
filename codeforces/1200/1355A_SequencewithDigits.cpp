#include <iostream>
#include <algorithm>
using namespace std;

long long getMinimumDigit(long long n) {
    long long minimum = 9;

    while (n > 0) {
        minimum = min(minimum, n % 10);
        n /= 10;
    }

    return minimum;
}

long long getMaximumDigit(long long n) {
    long long maximum = 0;

    while (n > 0) {
        maximum = max(maximum, n % 10);
        n /= 10;
    }

    return maximum;
}

long long solve() {
    long long A, K;
    cin >> A >> K;

    for (long long i = 1; i < K; i++) {
        long long minimum = getMinimumDigit(A);
        long long maximum = getMaximumDigit(A);

        if (minimum == 0) {
            break;
        }

        A += minimum * maximum;
    }

    return A;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << '\n';
    }

    return 0;
}