#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x;

        cin >> n >> x;

        vector<long long> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        long long low = 1;
        long long high = *max_element(a.begin(), a.end()) + x;
        long long answer = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long required = 0;

            for (long long height : a) {
                if (height < mid) {
                    required += mid - height;
                }

                if (required > x)
                    break;
            }

            if (required <= x) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}