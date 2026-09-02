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

        vector<long long> values;
        vector<long long> validIndices;

        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;

            if (x < i) {
                values.push_back(x);
                validIndices.push_back(i);
            }
        }

        sort(values.begin(), values.end());

        long long answer = 0;

        for (long long i : validIndices) {
            auto it = upper_bound(values.begin(), values.end(), i);
            answer += values.end() - it;
        }

        cout << answer << '\n';
    }

    return 0;
}