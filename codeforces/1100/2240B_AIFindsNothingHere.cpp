#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll power(ll base, ll exp, ll mod) {
    base %= mod;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n, m, r, c;
        scanf("%lld %lld %lld %lld", &n, &m, &r, &c);

        ll R = max(0LL, n - r + 1);
        ll C = max(0LL, m - c + 1);

        // exponent = n*m - R*C  (fits in ll for n,m up to ~1e9; use __int128 if larger)
        ll totalFree = n * m - R * C;

        // reduce exponent mod (MOD-1) via Fermat's little theorem (MOD is prime, base=2 coprime to MOD)
        ll exponent = totalFree % (MOD - 1);
        printf("%lld\n", power(2, exponent, MOD));
    }
}