#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int ones = count(s.begin(), s.end(), '1');
    int zeros = n - ones;

    int pref0 = 0, pref1 = 0;
    int ans = n;

    for (int i = 0; i <= n; ++i) {
        ans = min(ans, pref1 + zeros - pref0);
        ans = min(ans, pref0 + ones - pref1);

        if (i < n) {
            if (s[i] == '0')
                ++pref0;
            else
                ++pref1;
        }
    }

    cout << ans << '\n';
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