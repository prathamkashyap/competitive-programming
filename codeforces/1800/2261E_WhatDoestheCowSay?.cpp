#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int size;
    vector<int> tree;

public:
    SegmentTree(const vector<int>& a) {
        int n = a.size();
        size = 1;

        while (size < n) {
            size <<= 1;
        }

        tree.assign(2 * size, INT_MIN);

        for (int i = 0; i < n; i++) {
            tree[size + i] = a[i];
        }

        for (int i = size - 1; i >= 1; i--) {
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }

    int query(int l, int r) {
        int ans = INT_MIN;

        l += size;
        r += size;

        while (l < r) {
            if (l & 1) {
                ans = max(ans, tree[l++]);
            }

            if (r & 1) {
                ans = max(ans, tree[--r]);
            }

            l >>= 1;
            r >>= 1;
        }

        return ans;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> balance(n + 1, 0);
    vector<int> openCount(n + 1, 0);
    vector<int> match(n, -1);

    vector<int> st;
    vector<int> closingPositions;

    for (int i = 0; i < n; i++) {
        balance[i + 1] = balance[i];
        openCount[i + 1] = openCount[i];

        if (s[i] == '(') {
            balance[i + 1]++;
            openCount[i + 1]++;
            st.push_back(i);
        } else {
            balance[i + 1]--;

            int j = st.back();
            st.pop_back();

            match[i] = j;
            match[j] = i;

            closingPositions.push_back(i);
        }
    }

    SegmentTree seg(balance);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != '(') {
            continue;
        }

        int x = lower_bound(
            closingPositions.begin(),
            closingPositions.end(),
            i
        ) - closingPositions.begin();

        if (i + 1 < n && s[i + 1] == ')' && x <= k) {
            ans = max(
                ans,
                min(n / 2, balance[i + 1] + k)
            );
        }

        if (i > 0 && s[i - 1] == '(') {
            continue;
        }

        int y = upper_bound(
            closingPositions.begin(),
            closingPositions.end(),
            match[i]
        ) - closingPositions.begin();

        if (x <= k) {
            int remaining = k - x;

            if (y - x <= remaining) {
                ans = max(ans, y);
            } else {
                int j = closingPositions[x + remaining];

                ans = max(ans, openCount[j]);
            }
        }

        if (y - x <= k) {
            ans = max(ans, y - x);
        } else {
            int j = closingPositions[x + k];

            ans = max(
                ans,
                seg.query(i, j + 1) - balance[i]
            );
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