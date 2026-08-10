#include <iostream>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    int odd = 0;
    int even = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        if (value % 2)
            odd++;
        else
            even++;
    }

    bool possible = false;

    for (int oddCount = 1; oddCount <= odd && oddCount <= x; oddCount += 2) {
        int evenCount = x - oddCount;

        if (evenCount <= even) {
            possible = true;
            break;
        }
    }

    cout << (possible ? "Yes" : "No") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}