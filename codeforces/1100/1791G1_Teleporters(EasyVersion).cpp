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
        long long c;
        cin >> n >> c;

        vector<long long> cost(n);

        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;

            cost[i] = a + (i + 1);
        }

        sort(cost.begin(), cost.end());

        long long sum = 0;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            if (sum + cost[i] <= c) {
                sum += cost[i];
                answer++;
            } else {
                break;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}