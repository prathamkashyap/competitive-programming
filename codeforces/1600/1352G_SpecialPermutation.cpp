#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << -1 << '\n';
        return;
    }

    for (int i = n; i >= 1; i--) {
        if (i % 2 == 1) {
            cout << i << ' ';
        }
    }

    cout << "4 2 ";

    for (int i = 6; i <= n; i += 2) {
        cout << i << ' ';
    }

    cout << '\n';
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