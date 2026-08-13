#include <iostream>

using namespace std;

using ll = long long;

const ll MOD = 1000000007;

ll power(ll base, ll exponent) {
    ll result = 1;

    while (exponent > 0) {
        if (exponent & 1)
            result = result * base % MOD;

        base = base * base % MOD;
        exponent >>= 1;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        cout << power(n, k) << '\n';
    }

    return 0;
}