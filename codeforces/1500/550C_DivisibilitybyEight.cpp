#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(const string&s, const string& target) {
  int j = 0;

  for (char c : s) {
    if (j < (int)target.size() && c == target[j]) {
      j++;
    }
  }

  return j == (int)target.size();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  for (int x = 0; x <= 999; x++) 
  {
    if (x % 8 != 0) {
      continue;
    }

    string target = to_string(x);
    if (isSubsequence(s, target)) {
      cout << "YES\n";
      cout << target << '\n';
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}