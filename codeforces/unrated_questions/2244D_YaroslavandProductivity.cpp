#include<iostream>
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll NEG = -(1LL << 60);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) {
      cin >> a[i];
    }

    vector<int> can(n+1, 0);

    for (int i=0; i<m; i++) {
      int x;
      cin >> x;
      can[x] = 1;
    }

    ll dp[2] = {a[n], can[n] ? -a[n] : NEG};

    for (int i=n-1; i>=1; i--) {
      ll ndp[2] = {NEG, NEG};

      for (int p=0; p<2; p++){
        if (dp[p] == NEG)
          continue;
        if (can[i]) {
          for (int np : {p, p^1}) {
            ll val = dp[p] + (np ? -a[i] : a[i]);
            ndp[np] = max(ndp[np], val);
          }
        }
        else {
          int np = p;
          ll val = dp[p] + (np ? -a[i] : a[i]);
          ndp[np] = max(ndp[np], val);
        }
      }
      dp[0] = ndp[0];
      dp[1] = ndp[1];
    }

    cout << max(dp[0], dp[1]) << "\n";
  }
  return 0;
}