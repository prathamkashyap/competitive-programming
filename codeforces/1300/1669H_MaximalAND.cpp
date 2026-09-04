#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long answer = 0;

        for (int bit = 30; bit >= 0; bit--) {
            long long need = 0;
            long long mask = 1LL << bit;

            for (int i = 0; i < n; i++) {
                if ((a[i] & mask) == 0) {
                    need++;
                }
            }

            if (need <= k) {
                k -= need;
                answer |= mask;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}