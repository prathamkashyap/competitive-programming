#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int n, x, m;
    cin >> n >> x >> m;

    int left = x;
    int right = x;

    for (int i=0; i<m; i++) {
      int l, r;
      cin >> l >> r;

      if (r >= left && l <= right) {
        left = min(left, l);
        right = max(right, r);
      }
    }

    cout << right - left + 1 << '\n';
  }

  return 0;
}