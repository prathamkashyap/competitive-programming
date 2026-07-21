#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  vector<vector<int>> adj(n+1);

  int64 original = 0;

  for (int i=0; i<m; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < m; i++) {
    original += abs(a[i] - a[i - 1]);

    if (a[i] == a[i - 1])
        continue;

    adj[a[i]].push_back(a[i - 1]);
    adj[a[i - 1]].push_back(a[i]);
}

  int64 best = original;

  for (int v = 1; v <= n; v++) {
        if (adj[v].empty())
            continue;

        auto &vec = adj[v];
        sort(vec.begin(), vec.end());

        int med = vec[vec.size() / 2];

        int64 cur = original;

        for (int x : vec)
            cur -= abs(v - x);

        for (int x : vec)
            cur += abs(med - x);

        best = min(best, cur);
    }

    cout << best << '\n';

    return 0;
}