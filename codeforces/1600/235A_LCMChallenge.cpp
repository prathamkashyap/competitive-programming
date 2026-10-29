#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (n <= 2) {
        cout << n << '\n';
    } else if (n % 2 == 1) {
        cout << n * (n - 1) * (n - 2) << '\n';
    } else if (n % 3 != 0) {
        cout << n * (n - 1) * (n - 3) << '\n';
    } else {
        cout << (n - 1) * (n - 2) * (n - 3) << '\n';
    }

    return 0;
}