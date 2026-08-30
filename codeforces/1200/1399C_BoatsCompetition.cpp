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

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int answer = 0;

        for (int target = 2; target <= 2 * n; target++) {
            int left = 0;
            int right = n - 1;
            int teams = 0;

            while (left < right) {
                int sum = a[left] + a[right];

                if (sum == target) {
                    teams++;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }

            answer = max(answer, teams);
        }

        cout << answer << '\n';
    }

    return 0;
}