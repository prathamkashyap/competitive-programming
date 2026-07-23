#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;

  string s;
  cin >> s;

  vector<int> freq(26, 0);

  for (char c : s)
    freq[c - 'a']++;

  string base = "";

  for (int i=0; i<26; i++) {
    if (freq[i] % k != 0) {
      cout << -1 << '\n';
      return 0;
    }

    base.append(freq[i] / k, char('a' + i));
  }

  for (int i=0; i<k; i++) 
    cout << base;

  cout << '\n';

  return 0;
}