#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve() {

    vector<string> grid(9);

    for (int i = 0; i < 9; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '2';
            }
        }
    }

    for (const string &row : grid) {
        cout << row << '\n';
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}