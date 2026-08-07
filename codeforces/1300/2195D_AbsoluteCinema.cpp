#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> f(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }

  vector<ll> a(n+1);

  ll known = 0;

  for (int i = 2; i <= n - 1; i++) {
    a[i] = (f[i + 1] - 2 * f[i] + f[i - 1]) / 2;
    known += a[i];
  }

  ll x = f[2] - f[1] + known;
  ll y = f[n] - f[n-1] - known;

  a[n] = (x - 2 * y) / 3;
  a[1] = (2 * x - y) / 3;

  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}