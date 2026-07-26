// #include<bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n+1);
    int mn = INT_MAX, mx = INT_MIN;

    for (int i=1; i<=n; i++) {
      cin >> a[i];

      if (i & 1) {
        mn = min(mn, a[i]);
      }
      else {
        mx = max(a[i], mx);
      }
    }

    if (n & 1) {
      cout << "NO\n";
    }
    else {
      cout << (mx + 2 <= mn ? "YES\n" : "NO\n");
    }
  }
  return 0;
}