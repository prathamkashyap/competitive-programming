#include <iostream>
#include <numeric>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;

        ll lcm = a / gcd(a, b) * b;

        ll positive = n / a - n / lcm;
        ll negative = n / b - n / lcm;

        ll positiveSum = positive * (2 * n - positive + 1) / 2;
        ll negativeSum = negative * (negative + 1) / 2;

        cout << positiveSum - negativeSum << '\n';
    }

    return 0;
}