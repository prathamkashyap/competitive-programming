#include <iostream>
using namespace std;

bool solve() {
    long long N, A, B;
    cin >> N >> A >> B;

    long long x = 1;

    while (x <= N) {
        if ((N - x) % B == 0) {
            return true;
        }

        if (A == 1) {
            break;
        }

        x *= A;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cout << (solve() ? "Yes\n" : "No\n");
    }

    return 0;
}