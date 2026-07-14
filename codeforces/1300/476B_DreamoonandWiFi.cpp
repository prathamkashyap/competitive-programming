#include<iostream>
#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int target = 0;
int total = 0;
int favorable = 0;

void dfs(int idx, int pos) {
    if (idx == s2.size()) {
        total++;
        if (pos == target)
            favorable++;
        return;
    }

    if (s2[idx] == '+')
        dfs(idx + 1, pos + 1);

    else if (s2[idx] == '-')
        dfs(idx + 1, pos - 1);

    else {
        dfs(idx + 1, pos + 1);
        dfs(idx + 1, pos - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;

    for (char c : s1)
        target += (c == '+') ? 1 : -1;

    dfs(0, 0);

    cout << fixed << setprecision(12)
         << (double)favorable / total << '\n';

    return 0;
}