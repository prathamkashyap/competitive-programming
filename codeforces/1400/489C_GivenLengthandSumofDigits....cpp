#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, s;
    cin >> m >> s;

    if ((s == 0 && m > 1) || s > 9 * m) {
        cout << "-1 -1\n";
        return 0;
    }

    if (m == 1 && s == 0) {
        cout << "0 0\n";
        return 0;
    }

    // Largest number
    string mx = "";
    int sum = s;
    for (int i = 0; i < m; i++) {
        int d = min(9, sum);
        mx += char('0' + d);
        sum -= d;
    }

    // Smallest number
    string mn(m, '0');
    sum = s - 1;  // Reserve 1 for the first digit

    for (int i = m - 1; i > 0; i--) {
        int d = min(9, sum);
        mn[i] = char('0' + d);
        sum -= d;
    }

    mn[0] = char('0' + sum + 1);

    cout << mn << " " << mx << '\n';

    return 0;
}