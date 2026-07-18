#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int p, q, l, r;
  cin >> p >> q >> l >> r;

  vector<pair<int, int>> Z(p), X(q);

  for (int i=0; i<p; i++) {
    cin >> Z[i].first >> Z[i].second;
  }

  for (int i=0; i<q; i++) {
    cin >> X[i].first >> X[i].second;
  }

  int ans = 0;

  for (int t = l; t <= r; t++) {
    bool ok = false;

    for (int i=0; i<q && !ok; i++) {
      int s = X[i].first + t;
      int e = X[i].second + t;

      for (int j=0; j<p; j++)  {
        if (max(s, Z[j].first) <= min(e, Z[j].second)) {
          ok = true;
          break;
        }
      }
    }

    if (ok)
      ans++;

  }
  cout << ans << "\n";
  return 0;
}