#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k, x;

    cin >> n >> k >> x;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> needed;
    int groups = 1;

    for (int i = 1; i < n; i++) {
        long long gap = a[i] - a[i - 1];

        if (gap > x) {
            groups++;

            // Number of students needed to bridge this gap
            long long cnt = (gap - 1) / x;
            needed.push_back(cnt);
        }
    }

    sort(needed.begin(), needed.end());

    for (long long cnt : needed) {
        if (cnt <= k) {
            k -= cnt;
            groups--;
        } else {
            break;
        }
    }

    cout << groups << '\n';

    return 0;
}