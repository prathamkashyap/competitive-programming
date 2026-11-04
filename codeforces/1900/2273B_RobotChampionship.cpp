#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> ans;

    for (int phase = 0; phase < 3; phase++) {
        int start = 2 * n;

        if (n % 3 == 0 && phase == 1) {
            start--;
        }

        for (int v = start; v >= 2; v -= 2) {
            ans.push_back(v);
        }
    }

    cout << ans.size() << '\n';

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i + 1 == (int)ans.size() ? '\n' : ' ');
    }
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