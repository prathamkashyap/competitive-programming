#include <iostream>
using namespace std;

bool solve() {
    long long N;
    cin >> N;

    for (int a = 0; a <= 10; a++) {
        long long remaining = N - 111LL * a;

        if (remaining >= 0 && remaining % 11 == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}