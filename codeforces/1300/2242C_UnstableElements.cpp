#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> blockLengths;

    // Compute lengths of consecutive equal-value blocks
    int cnt = 1;
    int prev;
    cin >> prev;

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;

        if (x == prev) {
            cnt++;
        } else {
            blockLengths.push_back(cnt);
            cnt = 1;
            prev = x;
        }
    }
    blockLengths.push_back(cnt);

    sort(blockLengths.begin(), blockLengths.end());

    int alive = blockLengths.size();
    ll currentSum = n;
    int ans = 0;

    int idx = 0;

    // d = number of delete operations
    for (int d = 0; alive > 0; d++) {

        // Remove blocks that disappear after d deletions
        while (idx < (int)blockLengths.size() && blockLengths[idx] == d) {
            currentSum -= blockLengths[idx];
            alive--;
            idx++;
        }

        if (alive == 0)
            break;

        ll baseLength = currentSum - 1LL * alive * d;

        if (k < baseLength)
            continue;

        if ((k - baseLength) % alive == 0)
            ans++;
    }

    cout << ans << '\n';
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