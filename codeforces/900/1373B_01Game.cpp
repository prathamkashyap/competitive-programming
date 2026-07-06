#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  if (!(cin>>T)) return 0;
  while (T--) {
    string s;
    cin >> s;
    int z=0, o=0;
    for (char c:s) {
      if (c == '0')
        ++z;
      else
        ++o;
    }
    int moves = min(z,o);
    cout << (moves%2 ? "DA" : "NET") << "\n";
  }
  return 0;
}