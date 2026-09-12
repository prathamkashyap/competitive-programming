#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        int answer = 0;

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int ones = 0;

                ones += grid[i][j] - '0';
                ones += grid[j][n - 1 - i] - '0';
                ones += grid[n - 1 - i][n - 1 - j] - '0';
                ones += grid[n - 1 - j][i] - '0';

                answer += min(ones, 4 - ones);
            }
        }

        cout << answer << '\n';
    }

    return 0;
}