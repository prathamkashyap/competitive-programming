#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1];
        if (s[i] == s[i - 1])
            prefix[i]++;
    }
    prefix[n] = prefix[n - 1];

    int m;
    cin >> m;

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r - 1] - prefix[l - 1] << '\n';
    }

    return 0;
}