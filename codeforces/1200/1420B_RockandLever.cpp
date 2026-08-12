#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
    vector<long long> cnt(31, 0);

    for (int i=0; i<n; i++) {
      long long x;
      cin >> x;

      int bit = 63 - __builtin_clzll(x);
      cnt[bit]++;
    }

    long long answer = 0;
    
    for (long long c : cnt) {
      answer += c * (c - 1)/2;
    }

    cout << answer << '\n';

  }
  return 0;
}