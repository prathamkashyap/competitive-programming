#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> order;
    queue<pair<int, int>> q;

    int startX = -1, startY = -1;

    for (int i = 0; i < n && startX == -1; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    q.push({startX, startY});
    visited[startX][startY] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        order.push_back({x, y});

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (grid[nx][ny] != '.' || visited[nx][ny]) {
                continue;
            }

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    for (int i = static_cast<int>(order.size()) - k;
         i < static_cast<int>(order.size()); i++) {
        auto [x, y] = order[i];
        grid[x][y] = 'X';
    }

    for (const string& row : grid) {
        cout << row << '\n';
    }

    return 0;
}