#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        long long ans = 0;

        // Diagonals starting from the first column
        for (int i = 0; i < n; i++) {
            int mn = 0;
            int x = i, y = 0;
            while (x < n && y < n) {
                mn = min(mn, a[x][y]);
                x++;
                y++;
            }
            ans += -mn;
        }

        // Diagonals starting from the first row (excluding main diagonal)
        for (int j = 1; j < n; j++) {
            int mn = 0;
            int x = 0, y = j;
            while (x < n && y < n) {
                mn = min(mn, a[x][y]);
                x++;
                y++;
            }
            ans += -mn;
        }

        cout << ans << '\n';
    }

    return 0;
}