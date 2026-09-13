#include <iostream>
using namespace std;

int solve() {

    int N, K;
    cin >> N >> K;

    if (N % 2 == 1) {
        cout << 1 << ' ' << N / 2 << ' ' << N / 2 << '\n';
    }
    else if (N % 4 != 0) {
        cout << 2 << ' ' << N / 2 - 1 << ' ' << N / 2 - 1 << '\n';
    }
    else {
        cout << N / 2 << ' ' << N / 4 << ' ' << N / 4 << '\n';
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}