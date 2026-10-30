#include <iostream>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    int degree = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        if (u == x || v == x) {
            degree++;
        }
    }

    if (degree <= 1 || n % 2 == 0) {
        cout << "Ayush\n";
    } else {
        cout << "Ashish\n";
    }
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