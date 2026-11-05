#include <bits/stdc++.h>
using namespace std;

bool valid(const string& s) {
    array<int, 3> cnt = {1, 0, 0};
    int rem = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') {
            rem = (rem + (i % 2 == 0 ? 2 : 1)) % 3;
        }

        cnt[rem]++;
    }

    return *max_element(cnt.begin(), cnt.end()) -
           *min_element(cnt.begin(), cnt.end()) <= 1;
}

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return;
    }

    if (n == 2) {
        cout << "10\n";
        return;
    }

    for (int a = n / 3; a <= n / 3 + 1; a++) {
        for (int b = 2 * n / 3; b <= 2 * n / 3 + 1; b++) {
            for (int last = 0; last <= 1; last++) {
                if (a >= b || (last && b >= n)) {
                    continue;
                }

                string s(n, '0');

                s[a - 1] = '1';
                s[b - 1] = '1';

                if (last) {
                    s[n - 1] = '1';
                }

                if (valid(s)) {
                    cout << s << '\n';
                    return;
                }
            }
        }
    }
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