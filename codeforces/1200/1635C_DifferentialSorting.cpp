#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> a(N);

        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        // The last two elements can never be changed.
        if (a[N - 2] > a[N - 1]) {
            cout << -1 << '\n';
            continue;
        }

        // If the last element is negative, we cannot
        // construct a sorted array unless it is already sorted.
        if (a[N - 1] < 0) {
            bool sorted = true;

            for (int i = 1; i < N; i++) {
                if (a[i - 1] > a[i]) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) {
                cout << 0 << '\n';
            } else {
                cout << -1 << '\n';
            }

            continue;
        }

        // Change every element before the last two.
        cout << N - 2 << '\n';

        for (int i = 1; i <= N - 2; i++) {
            cout << i << ' ' << N - 1 << ' ' << N << '\n';
        }
    }

    return 0;
}