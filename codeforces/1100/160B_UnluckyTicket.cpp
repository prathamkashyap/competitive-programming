#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string s;
  cin >> s;

  string a = s.substr(0, n);
  string b = s.substr(n);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  bool less = true;
  bool greater = true;

  for (int i = 0; i < n; i++) {
      if (a[i] >= b[i]) less = false;
      if (a[i] <= b[i]) greater = false;
  }

  cout << (less || greater ? "YES" : "NO");
  return 0;
}