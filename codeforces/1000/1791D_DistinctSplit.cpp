#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<int> prefix(n);
        vector<int> suffix(n);

        bool seen[26] = {};

        for (int i = 0; i < n; i++) {
            if (!seen[s[i] - 'a']) {
                seen[s[i] - 'a'] = true;
                prefix[i]++;
            }

            if (i > 0)
                prefix[i] += prefix[i - 1];
        }

        fill(seen, seen + 26, false);

        for (int i = n - 1; i >= 0; i--) {
            if (!seen[s[i] - 'a']) {
                seen[s[i] - 'a'] = true;
                suffix[i]++;
            }

            if (i < n - 1)
                suffix[i] += suffix[i + 1];
        }

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, prefix[i] + suffix[i + 1]);
        }

        cout << ans << '\n';
    }

    return 0;
}