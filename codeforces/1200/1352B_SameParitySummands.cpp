#include <iostream>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int oddLast = n - k + 1;

  if (oddLast > 0 && oddLast % 2 == 1) {
    cout << "YES\n";

    for (int i=0; i<k-1; i++) {
      cout << 1 << " ";
    }

    cout << oddLast << '\n';
    return;
  }

  int evenLast = n - 2 * (k - 1);

  if (evenLast > 0 && evenLast % 2 == 0) {
    cout << "YES\n";

    for (int i=0; i < k - 1; i++) {
      cout << 2 << ' ';
    }

    cout << evenLast << "\n";
    return;
  }

  cout << "NO\n";
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