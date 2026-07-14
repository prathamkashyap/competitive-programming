#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> par(n+1, 0);
        vector<vector<int>> children(n+1);

        for (int i = 2; i <= n; i++) {
            cin >> par[i];
            children[par[i]].push_back(i);
        }

        vector<long long> a(n+1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<long long> mn(n+1), mx(n+1), sz(n+1);
        bool ok = true;

        vector<int> order;
        order.reserve(n);

        vector<int> stack1{1};
        vector<char> pushedChildren(n+1, 0);

        while (!stack1.empty()) {
            
          int v = stack1.back();
          if (!pushedChildren[v]) {
              pushedChildren[v] = 1;
              for (int c : children[v]) 
                stack1.push_back(c);
          } 
          
          else {
              stack1.pop_back();
              order.push_back(v);
          }
        }

        for (int v : order) {

            if (a[v] > 0) {
                mn[v] = mx[v] = a[v];
                sz[v] = 1;
            } 
            
            else {
              long long curmin = LLONG_MAX, curmax = LLONG_MIN, cursz = 0;
              for (int c : children[v]) {
                  curmin = min(curmin, mn[c]);
                  curmax = max(curmax, mx[c]);
                  cursz += sz[c];
              }
              mn[v] = curmin; mx[v] = curmax; sz[v] = cursz;

              if (curmax - curmin + 1 != cursz) ok = false;

              int m = children[v].size();
              if (m >= 2) {
                  int descents = 0;

                  for (int i = 0; i < m; i++) {
                      long long cur = mn[children[v][i]];
                      long long nxt = mn[children[v][(i+1)%m]];
                      if (cur > nxt) descents++;
                  }
                  
                  if (descents > 1) ok = false;
              }
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}