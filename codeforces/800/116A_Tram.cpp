#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    if (!(cin >> n)) return 0;
    int cur = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        int a, b; 
        cin >> a >> b;
        cur -= a;
        cur += b;
        mx = max(mx, cur);
    }
    cout << mx << "\n";
    return 0;
}
