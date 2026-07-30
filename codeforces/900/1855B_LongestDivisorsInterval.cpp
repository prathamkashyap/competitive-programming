#include <iostream>

using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    ll i = 1;

    while (n % i == 0) {
        i++;
    }

    cout << i - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}