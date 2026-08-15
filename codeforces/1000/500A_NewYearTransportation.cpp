#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  vector<int> a(n+1);

  for (int i=1; i<n; i++) {
    cin >> a[i];
  }

  int pos = 1;

  while (pos < t) {
    pos += a[pos];
  }

  if (pos == t)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}