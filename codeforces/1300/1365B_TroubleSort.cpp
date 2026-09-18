#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    bool hasZero = false;
    bool hasOne = false;

    for (int i = 0; i < N; i++) {
        cin >> b[i];

        if (b[i] == 0) {
            hasZero = true;
        } else {
            hasOne = true;
        }
    }

    if (hasZero && hasOne) {
        cout << "YES\n";
        return 0;
    }

    if (is_sorted(a.begin(), a.end())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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