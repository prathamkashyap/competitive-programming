#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        long long ans = 0;

        for (int first = 0; first <= 1; first++) {
            for (int second = 0; second <= 1; second++) {

                if (s[0] != '?' && s[0] - '0' != first)
                    continue;

                if (s[1] != '?' && s[1] - '0' != second)
                    continue;

                int a = first;
                int b = second;
                bool ok = true;

                for (int i = 2; i < n; i++) {
                    int cur;

                    if (s[i] == '?')
                        cur = 1 - a;
                    else
                        cur = s[i] - '0';

                    if (cur == a) {
                        ok = false;
                        break;
                    }

                    a = b;
                    b = cur;
                }

                if (ok)
                    ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}