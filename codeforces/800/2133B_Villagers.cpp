#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int n;
  for(int i=0; i < t; i++) {
    cin >> n;
    vector<int> g(n);
    for (int i=0; i<n; i++) {
      cin >> g[i];
    }
    sort(g.rbegin(), g.rend());

    long long total = 0;
    for (int i=0; i+1 < n; i+=2) {
      total += g[i];
    }
    if (n % 2 == 1) {
        total += g[n-1];
    }
    cout << total << "\n";
  }
  return 0;
}