#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<int> prefix(n, 0);
        for (int i = 1; i <= n - 1; i++) {
            int conflict = (s[i-1] == s[i]) ? 1 : 0;
            prefix[i] = prefix[i-1] + conflict;
        }

        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            if (l == r) {
                cout << "YES\n";
                continue;
            }
            int cnt = prefix[r-1] - prefix[l-1];
            int need = (cnt + 1) / 2;
            cout << (k >= need ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}