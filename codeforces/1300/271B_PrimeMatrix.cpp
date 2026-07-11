#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

vector<bool> prime(MAX + 1, true);
vector<int> cost(MAX + 1);

void sieve() {
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                prime[j] = false;
        }
    }

    int nxt = -1;

    for (int i = MAX; i >= 0; i--) {
        if (prime[i])
            nxt = i;
        cost[i] = nxt - i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int n, m;
    cin >> n >> m;

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;

            row[i] += cost[x];
            col[j] += cost[x];
        }
    }

    int ans = INT_MAX;

    for (int x : row)
        ans = min(ans, x);

    for (int x : col)
        ans = min(ans, x);

    cout << ans << '\n';

    return 0;
}