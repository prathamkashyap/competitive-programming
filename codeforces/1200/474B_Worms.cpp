#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> prefix(n);

  cin >> prefix[0];
  for (int i=1; i < n; i++) {
    int x;
    cin >> x;
    prefix[i] = prefix[i-1] + x;
  }

  int m;
  cin >> m;

  while (m--) {
    int worm;
    cin >> worm;

    cout << lower_bound(prefix.begin(), prefix.end(), worm) - prefix.begin() + 1 << '\n';
  }

  return 0;
}