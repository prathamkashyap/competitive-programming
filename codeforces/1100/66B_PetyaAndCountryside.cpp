#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    if (!(cin >> n)) return 0;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<int> L(n, 1), R(n, 1);
    for (int i = 1; i < n; ++i)
        if (h[i] >= h[i-1]) L[i] = L[i-1] + 1;

    for (int i = n - 2; i >= 0; --i)
        if (h[i] >= h[i+1]) R[i] = R[i+1] + 1;

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, L[i] + R[i] - 1);

    cout << ans << "\n";
    return 0;
}
