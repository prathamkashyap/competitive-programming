#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long k, x;
        cin >> k >> x;

        cout << (x << k) << '\n';
    }

    return 0;
}