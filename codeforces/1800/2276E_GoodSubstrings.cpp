#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<array<int, 10>> nxt(n + 1);

    for (int d = 0; d < 10; d++) {
        nxt[n][d] = n;
    }

    for (int i = n - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - '0'] = i;
    }

    vector<ll> diffA(n + 1, 0);
    vector<ll> diffB(n + 1, 0);

    auto add = [&](int l, int r, ll a, ll b) {
        if (l > r) return;

        diffA[l] += a;
        diffA[r + 1] -= a;

        diffB[l] += b;
        diffB[r + 1] -= b;
    };

    for (int l = 0; l < n; l++) {
        int p = l;

        for (char c : string("202")) {
            if (p >= n) break;
            p = nxt[p][c - '0'];

            if (p < n) p++;
        }

        if (p >= n) continue;

        int p25 = nxt[p][5];
        int p26 = nxt[p][6];

        if (p25 >= p26) continue;

        add(l, p25, 0, p26 - p25);
        add(p25 + 1, p26 - 1, -1, p26);
    }

    ll a = 0, b = 0;

    for (int i = 0; i < n; i++) {
        a += diffA[i];
        b += diffB[i];

        ll total = 1LL * (i + 1) * (n - i);
        ll bad = a * i + b;

        cout << total - bad << (i + 1 == n ? '\n' : ' ');
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