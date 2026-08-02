#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  unordered_map<string, string> mp;

  for (int i=0; i<m; i++) {
    string a, b;
    cin >> a >> b;
    mp[a] = b;
  }

  for (int i=0; i<n; i++) {
    string word;
    cin >> word;

    if (mp[word].length() < word.length()) {
      cout << mp[word];
    }
    else {
      cout << word;
    }

    if (i != n-1)
      cout << " ";
  }
  return 0;
}