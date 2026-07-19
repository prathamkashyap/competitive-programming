#include<iostream>
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

    vector<int> a(n);
    
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    
    int ans = 0;

    for (int i=0; i<n-1; i++) {
      int x = min(a[i], a[i+1]);
      int y = max(a[i], a[i+1]);

      while (2 * x < y) {
        x *= 2;
        ans++;
      }
    }

    cout << ans << '\n';
  }
  return 0;
}