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
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> a(n, vector<long long>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        long long answer = 0;

        for (int j = 0; j < m; j++) {
            vector<long long> column;

            for (int i = 0; i < n; i++) {
                column.push_back(a[i][j]);
            }

            sort(column.begin(), column.end());

            for (int i = 0; i < n; i++) {
                long long coefficient = 2LL * i - n + 1;
                answer += column[i] * coefficient;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}