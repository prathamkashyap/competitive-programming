#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n), t(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        cin >> t[i];

    long long base = 0;

    for (int i = 0; i < n; i++) {
        if (t[i] == 1)
            base += a[i];
    }

    long long extra = 0;

    for (int i = 0; i < k; i++) {
        if (t[i] == 0)
            extra += a[i];
    }

    long long best = extra;

    for (int i = k; i < n; i++) {
        if (t[i] == 0)
            extra += a[i];
        if (t[i - k] == 0)
            extra -= a[i - k];

        best = max(best, extra);
    }

    cout << base + best << '\n';

    return 0;
}