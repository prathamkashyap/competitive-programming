#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m, k;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans[MAXN][MAXN];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        cin >> grid[i];

    while (k--) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        if (!vis[x][y]) {
            queue<pair<int, int>> q;
            vector<pair<int, int>> cells;

            q.push({x, y});
            vis[x][y] = true;

            int stars = 0;

            while (!q.empty()) {
                auto [cx, cy] = q.front();
                q.pop();

                cells.push_back({cx, cy});

                for (int d = 0; d < 4; d++) {
                    int nx = cx + dx[d];
                    int ny = cy + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (grid[nx][ny] == '*') {
                        stars++;
                    } else if (!vis[nx][ny]) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }

            for (auto &cell : cells)
                ans[cell.first][cell.second] = stars;
        }

        cout << ans[x][y] << '\n';
    }

    return 0;
}