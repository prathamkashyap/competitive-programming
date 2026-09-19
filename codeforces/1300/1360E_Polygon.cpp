#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<string> grid(N);

    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '1') {
                if (i == N - 1 || j == N - 1) {
                    continue;
                }

                if (grid[i + 1][j] == '0' && grid[i][j + 1] == '0') {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}