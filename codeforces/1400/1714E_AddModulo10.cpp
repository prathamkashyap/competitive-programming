#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    bool special = false;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] % 10 == 0 || a[i] % 10 == 5) {
            special = true;
        }
    }

    if (special) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 10 == 5) {
                a[i] += 5;
            }
        }

        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                cout << "NO\n";
                return;
            }
        }

        cout << "YES\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        while (a[i] % 10 != 2) {
            a[i] += a[i] % 10;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i] % 20 != a[0] % 20) {
            cout << "NO\n";
            return;
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