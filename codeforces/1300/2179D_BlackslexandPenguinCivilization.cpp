#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int N = 1 << n;

        cout << N - 1 << ' ';

        for (int bits = 1; bits <= n; bits++) {
            int block = 1 << (n - bits);

            for (int j = 0; j < (1 << bits); j += 2) {
                cout << j * block + block - 1 << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}