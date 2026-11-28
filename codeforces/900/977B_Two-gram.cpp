#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    int freq[26][26] = {};
    int mx = 0;
    string ans;

    for (int i = 0; i < n - 1; i++) {
        int a = s[i] - 'A';
        int b = s[i + 1] - 'A';

        if (++freq[a][b] > mx) {
            mx = freq[a][b];
            ans = s.substr(i, 2);
        }
    }

    cout << ans << '\n';

    return 0;
}