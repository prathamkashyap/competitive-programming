#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> even, odd;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] & 1) {
            odd.push_back(a[i]);
        } else {
            even.push_back(a[i]);
        }
    }

    int evenMin = INT_MAX;
    int evenMax = INT_MIN;
    int oddMin = INT_MAX;
    int oddMax = INT_MIN;

    for (int x : even) {
        evenMin = min(evenMin, x);
        evenMax = max(evenMax, x);
    }

    for (int x : odd) {
        oddMin = min(oddMin, x);
        oddMax = max(oddMax, x);
    }

    bool possible = true;

    int maxEven = INT_MIN;

    for (int x : even) {
        if (maxEven > x &&
            oddMin > x &&
            oddMax < maxEven) {
            possible = false;
            break;
        }

        maxEven = max(maxEven, x);
    }

    int maxOdd = INT_MIN;

    for (int x : odd) {
        if (maxOdd > x &&
            evenMin > x &&
            evenMax < maxOdd) {
            possible = false;
            break;
        }

        maxOdd = max(maxOdd, x);
    }

    cout << (possible ? "YES" : "NO") << '\n';
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
