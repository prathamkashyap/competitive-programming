#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    if (k == 0) {
        if (a[0] == 1)
            cout << -1;
        else
            cout << a[0] - 1;
    }
    else {
        int ans = a[k - 1];

        if (k < n && a[k] == ans)
            cout << -1;
        else
            cout << ans;
    }

    return 0;
}