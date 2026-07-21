#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> cat;
int m, ans = 0;

void dfs(int node, int parent, int cnt) {
  if (cat[node]) {
    cnt++;
  }

  else {
    cnt = 0;
  }

  if (cnt > m) {
    return;
  }

  bool leaf = true;

  for (int child : adj[node]) {
    if (child == parent) {
      continue;
    }

    leaf = false;
    dfs(child, node, cnt);
  }

  if (leaf)
    ans++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> m;

  cat.resize(n+1);
  adj.resize(n+1);

  for (int i=1; i<=n; i++) {
    cin >> cat[i];
  }

  for (int i=0; i<n-1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 0, 0);
  
  cout << ans << '\n';

  return 0;
}