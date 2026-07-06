#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int q = 0; q < m; q++) {
            char type;
            long long l, r;
            cin >> type >> l >> r;
            for (int i = 0; i < n; i++) {
                if (a[i] >= l && a[i] <= r) {
                    if (type == '+') a[i]++;
                    else a[i]--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << a[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
}
