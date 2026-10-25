#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    ll g = 0;

    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[0]);
    }

    for (int i = 0; i < m; i++) {
        cout << gcd(g, a[0] + b[i]) << (i + 1 == m ? '\n' : ' ');
    }

    return 0;
}