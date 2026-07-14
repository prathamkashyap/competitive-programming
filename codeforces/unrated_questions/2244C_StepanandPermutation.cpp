#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> p, sz;
  DSU(int n) {
    p.resize(n+1);
    sz.assign(n+1, 1);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (sz[a] < sz[b]) 
      swap(a,b);
    
    p[b] = a;
    sz[a] += sz[b];
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;

    DSU dsu(n);

    for (int i=1; i+x <= n; i++) {
      dsu.unite(i, i+x);
    }

    for (int i=1; i+y<=n; i++) {
      dsu.unite(i, i+y);
    }

    bool ok = true;
    for (int i=1; i<=n; i++) {
      int v;
      cin >> v;

      if (dsu.find(i) != dsu.find(v))
        ok = false;
      }
    cout << (ok ? "YES" : "NO") << "\n";
  }
  return 0;
}