#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string s;
  cin >> s;

  int zeros = 0;
  int ones = 0;

  for (char c : s) {
    if (c == '0') {
      zeros++;
    }
    else {
      ones++;
    }
  }

  cout << abs(zeros - ones) << '\n';
  return 0;
}