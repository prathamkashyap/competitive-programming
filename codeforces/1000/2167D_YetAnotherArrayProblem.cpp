#include <iostream>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const vector<ll> primes = {
        2, 3, 5, 7, 11, 13, 17, 19,
        23, 29, 31, 37, 41, 43, 47, 53
    };

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll g;
        cin >> g;

        for (int i = 1; i < n; i++) {
            ll x;
            cin >> x;
            g = gcd(g, x);
        }

        for (ll p : primes) {
            if (g % p != 0) {
                cout << p << '\n';
                break;
            }
        }
    }

    return 0;
}