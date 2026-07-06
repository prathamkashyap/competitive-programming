#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        if (n <= 2) {
            cout << "YES\n";
            continue;
        }

        long long target = v[1];
        int mid = n / 2;

        int lessCount = 0;
        int equalCount = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] < target)
                lessCount++;
            else if (v[i] == target)
                equalCount++;
        }

        if (lessCount <= mid && mid < lessCount + equalCount)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

