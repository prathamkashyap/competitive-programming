#include <iostream>
using namespace std;

long long getSum(long long k, long long m) {
    if (m <= k) {
        return m * (m + 1) / 2;
    }

    long long t = m - k;

    return k * (k + 1) / 2
         + t * (2 * k - t - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long k, x;
        cin >> k >> x;

        long long left = 1;
        long long right = 2 * k - 1;

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (getSum(k, mid) >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        cout << left << '\n';
    }

    return 0;
}