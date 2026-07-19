#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        string t = s + s;

        vector<int> pos;
        for (int j = 0; j < m; j++)
            if (s[j] == '1')
                pos.push_back(j);

        if (pos.empty()) {
            cout << -1 << '\n';
            return 0;
        }

        vector<int> d(2 * m, INF);

        for (int p : pos) {
            d[p] = 0;
            d[p + m] = 0;
        }

        for (int j = 1; j < 2 * m; j++)
            d[j] = min(d[j], d[j - 1] + 1);
        for (int j = 2 * m - 2; j >= 0; j--)
            d[j] = min(d[j], d[j + 1] + 1);

        for (int j = 0; j < m; j++)
            dist[i][j] = min(d[j], d[j + m]);
    }

    int ans = INF;

    for (int col = 0; col < m; col++) {
        int sum = 0;
        for (int row = 0; row < n; row++)
            sum += dist[row][col];
        ans = min(ans, sum);
    }

    cout << ans << '\n';

    return 0;
}