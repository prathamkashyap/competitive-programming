#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n >= 0) {
        cout << n << '\n';
    } else {
        cout << max(n / 10, (n / 100) * 10 + n % 10) << '\n';
    }

    return 0;
}