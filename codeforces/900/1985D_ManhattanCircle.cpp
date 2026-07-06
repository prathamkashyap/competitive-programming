#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  if (!(cin>>T)) return 0;
  while (T--) {
    int n,m;
    cin >> n >> m;
    vector<string> g(n);
    for (int i=0; i<n; i++)
      cin >> g[i];

    int rmin = 0, rmax = -1, cmin = m, cmax = -1;
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        if (g[i][j] == '#') {
          rmin = min(rmin,i);
          rmax = max(rmax,i);
          cmin = min(cmin, j);
          cmax = max(cmax, j);
        }
        int cr = (rmin + rmax)/2, cc = (cmin + cmax)/2;
        cout << cr+1 << " " << cc+1 << "\n";
      }
    }
  }
}