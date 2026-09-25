#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N <= 2) {
        cout << 1 << '\n';

        for (int i = 2; i <= N + 1; i++) {
            cout << 1 << ' ';
        }

        cout << '\n';
        return 0;
    }

    // Sieve of Eratosthenes up to N + 1.
    vector<bool> isPrime(N + 2, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= N + 1; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N + 1; j += i) {
                isPrime[j] = false;
            }
        }
    }

    cout << 2 << '\n';

    for (int x = 2; x <= N + 1; x++) {
        if (isPrime[x]) {
            cout << 1 << ' ';
        } else {
            cout << 2 << ' ';
        }
    }

    cout << '\n';

    return 0;
}