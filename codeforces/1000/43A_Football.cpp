#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<string, int> cnt;

    string team, ans;
    int mx = 0;

    while (n--) {
        cin >> team;
        cnt[team]++;

        if (cnt[team] > mx) {
            mx = cnt[team];
            ans = team;
        }
    }

    cout << ans << '\n';

    return 0;
}