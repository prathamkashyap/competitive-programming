#include <iostream>
#include <numeric>

using namespace std;

using ll = long long;

int countFactors(ll &x, int factor) {
    int cnt = 0;

    while (x % factor == 0) {
        x /= factor;
        cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;

    ll g = gcd(a, b);

    a /= g;
    b /= g;

    int ans = 0;

    ans += countFactors(a, 2);
    ans += countFactors(a, 3);
    ans += countFactors(a, 5);

    ans += countFactors(b, 2);
    ans += countFactors(b, 3);
    ans += countFactors(b, 5);

    if (a != 1 || b != 1)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}