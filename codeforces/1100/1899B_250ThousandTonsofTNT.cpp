#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Prefix sums
        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
        }

        long long answer = 0;

        // len = size of each subarray
        for (int len = 1; len <= n; len++) {

            // n must be divisible by len
            if (n % len != 0)
                continue;

            long long minimum = LLONG_MAX;
            long long maximum = LLONG_MIN;

            // Divide the ORIGINAL array into blocks of size len
            for (int start = 0; start < n; start += len) {

                long long sum = prefix[start + len] - prefix[start];

                minimum = min(minimum, sum);
                maximum = max(maximum, sum);
            }

            answer = max(answer, maximum - minimum);
        }

        cout << answer << '\n';
    }

    return 0;
}