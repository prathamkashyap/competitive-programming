#include <iostream>

using namespace std;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int dots = 0;

  for (char c : s) {
    if (c == '.')
      dots++;
  }

  for (int i = 0; i+2 < n; i++) {
    if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
      cout << 2 << '\n';
      return;
    }
  }

  cout << dots << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}