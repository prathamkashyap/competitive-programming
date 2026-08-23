#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    if (m % n != 0) {
        cout << -1 << '\n';
        return 0;
    }

    long long x = m / n;
    int operations = 0;

    while (x % 2 == 0) {
        x /= 2;
        operations++;
    }

    while (x % 3 == 0) {
        x /= 3;
        operations++;
    }

    if (x == 1) {
        cout << operations << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}