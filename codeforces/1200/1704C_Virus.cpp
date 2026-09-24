#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long n;
        int m;

        cin >> n >> m;

        vector<long long> infected(m);

        for (int i = 0; i < m; i++) {
            cin >> infected[i];
        }

        sort(infected.begin(), infected.end());

        vector<long long> gaps;

        for (int i = 1; i < m; i++) {
            gaps.push_back(infected[i] - infected[i - 1] - 1);
        }

        gaps.push_back(n - infected[m - 1] + infected[0] - 1);

        sort(gaps.rbegin(), gaps.rend());

        long long days = 0;
        long long saved = 0;

        for (long long gap : gaps) {
            gap -= 2 * days;

            if (gap <= 0) {
                continue;
            }

            if (gap == 1) {
                saved += 1;
                days += 1;
            } else {
                saved += gap - 1;
                days += 2;
            }
        }

        cout << n - saved << '\n';
    }

    return 0;
}