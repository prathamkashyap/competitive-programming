#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long first = min(n, k);
        long long ans = first;
        long long rem = n - first;

        long long active = first;
        long long cost = 2;

        while (active > 0 && rem >= cost) {
            long long take = min(active, rem / cost);
            ans += take;
            rem -= take * cost;
            active = take;
            cost <<= 1;
        }

        cout << ans << '\n';
    }

    return 0;
}