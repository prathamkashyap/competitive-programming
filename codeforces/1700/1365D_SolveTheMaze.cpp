#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 'B') {
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int x = i + dx[d];
                int y = j + dy[d];

                if (x < 0 || x >= n || y < 0 || y >= m) {
                    continue;
                }

                if (grid[x][y] == 'G') {
                    cout << "NO\n";
                    return;
                }

                if (grid[x][y] == '.') {
                    grid[x][y] = '#';
                }
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    if (grid[n - 1][m - 1] != '#') {
        q.push({n - 1, m - 1});
        visited[n - 1][m - 1] = true;
    }

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (x < 0 || x >= n || y < 0 || y >= m) {
                continue;
            }

            if (grid[x][y] == '#' || visited[x][y]) {
                continue;
            }

            visited[x][y] = true;
            q.push({x, y});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'G' && !visited[i][j]) {
                cout << "NO\n";
                return;
            }

            if (grid[i][j] == 'B' && visited[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}