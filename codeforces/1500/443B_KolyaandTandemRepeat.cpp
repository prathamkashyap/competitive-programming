#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int k;
    cin >> k;

    int n = s.size();
    int ans = 0;

    for (int len = 1; len <= (n + k) / 2; len++) {
        for (int i = 0; i + 2 * len <= n + k; i++) {
            bool ok = true;

            for (int j = 0; j < len; j++) {
                int a = i + j;
                int b = i + len + j;

                if (a < n && b < n && s[a] != s[b]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans = max(ans, 2 * len);
        }
    }

    cout << ans << '\n';

    return 0;
}