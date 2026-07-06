#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int a[m];

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a, a + m);

    int ans = 1e9;

    // Check every group of n puzzles
    for (int i = 0; i <= m - n; i++) {
        ans = min(ans, a[i + n - 1] - a[i]);
    }

    cout << ans;

    return 0;
}