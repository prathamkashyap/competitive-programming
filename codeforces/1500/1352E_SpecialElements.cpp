#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> freq(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += a[j];

            if (sum > n) {
                break;
            }

            if (j > i) {
                freq[sum]++;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (freq[a[i]] > 0) {
            ans++;
        }
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