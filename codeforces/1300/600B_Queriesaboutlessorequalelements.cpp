#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  while (m--) {
    int x;
    cin >> x;

    cout << upper_bound(a.begin(), a.end(), x) - a.begin() << " ";
  }

  cout << '\n';
  return 0;
}