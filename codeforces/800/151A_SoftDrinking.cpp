#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, k, l, c, d, p, nl, np;
    if (!(cin >> n >> k >> l >> c >> d >> p >> nl >> np)) return 0;
    long long drink = (k * l) / nl;
    long long limes = c * d;
    long long salt  = p / np;
    cout << min({drink, limes, salt}) / n << '\n';
    return 0;
}
