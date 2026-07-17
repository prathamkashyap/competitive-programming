#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1 << 30;
const int MAX = 1000000;

int divisors[MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 1; i <= MAX; i++) {
        for (int j = i; j <= MAX; j += i)
            divisors[j]++;
    }

    long long ans = 0;

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                ans += divisors[i * j * k];
                ans %= MOD;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}