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
        int n;
        cin >> n;

        vector<long long> d(n);

        vector<long long> x(n);

        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }

        for (int i = 0; i < n; i++) {
            long long y;
            cin >> y;
            d[i] = y - x[i];
        }

        sort(d.begin(), d.end());

        int left = 0;
        int right = n - 1;
        int answer = 0;

        while (left < right) {
            if (d[left] + d[right] >= 0) {
                answer++;
                left++;
                right--;
            } else {
                left++;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}