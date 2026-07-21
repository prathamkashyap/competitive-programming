#include <iostream>
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int64> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        deque<int64> dq;

        for (int i = 0; i < n; i++) {
            dq.push_back(a[i]);

            while (dq.size() >= 2) {
                int m = dq.size();
                if (dq[m - 2] > dq[m - 1]) {
                    int64 x = dq[m - 2];
                    int64 y = dq[m - 1];
                    dq.pop_back();
                    dq.pop_back();
                    dq.push_back(y);
                    dq.push_back(x + y);
                } else {
                    break;
                }
            }
        }

        while (dq.size() >= 2) {
            int m = dq.size();
            if (dq[m - 2] > dq[m - 1]) {
                int64 x = dq[m - 2];
                int64 y = dq[m - 1];
                dq.pop_back();
                dq.pop_back();
                dq.push_back(y);
                dq.push_back(x + y);
            } else {
                break;
            }
        }

        cout << *max_element(dq.begin(), dq.end()) << '\n';
    }

    return 0;
}