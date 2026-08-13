#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, s;
        cin >> n >> s;

        vector<int> a(n);

        for (int &x : a)
            cin >> x;

        int left = 0;
        int sum = 0;
        int longest = -1;

        for (int right = 0; right < n; right++) {
            sum += a[right];

            while (sum > s) {
                sum -= a[left];
                left++;
            }

            if (sum == s) {
                longest = max(longest, right - left + 1);
            }
        }

        if (longest == -1)
            cout << -1 << '\n';
        else
            cout << n - longest << '\n';
    }

    return 0;
}