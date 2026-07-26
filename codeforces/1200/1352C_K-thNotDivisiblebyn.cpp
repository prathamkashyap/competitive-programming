#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    ll n, k;
    cin >> n >> k;

    ll ans = k + (k - 1) / (n - 1);
    cout << ans << '\n';
  }

  return 0;
}