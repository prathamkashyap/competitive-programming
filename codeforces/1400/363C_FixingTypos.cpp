#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  string ans;

  for (char c : s) {
    int n = ans.size();

    // Avoid AAA
    if (n >= 2 && ans[n-1] == c && ans[n-2] == c)
      continue;

    // Avoid AABB
    if (n >= 3 && ans[n-3] == ans[n-2] && 
      ans[n-2] != ans[n-1] &&
      ans[n-1] == c)
        continue;

      ans += c;
  }

  cout << ans << '\n';

  return 0;
}