#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, x, y;
        cin >> n >> m >> x >> y;
        for (long long i = 0, v; i < n; ++i) cin >> v;
        for (long long j = 0, v; j < m; ++j) cin >> v;
        cout << (n + m) << '\n';
    }
    return 0;
}
