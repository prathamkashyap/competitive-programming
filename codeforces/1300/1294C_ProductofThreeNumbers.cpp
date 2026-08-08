#include <iostream>
using namespace std;
using ll = long long;

void solve() {
  ll n;
  cin >> n;

  ll a = 0;
  ll b = 0;
  ll c = 0;

  for (ll i=2; i*i<=n; i++) {
    if (n % i == 0) {
      a = i;
      break;
    }
  }

  if (a == 0) {
    cout << "NO\n";
    return;
  }

  n /= a;

  for (ll i = a+1; i*i <= n; i++) {
    if (n % i == 0) {
      b = i;
      break;
    }
  }

  if (b == 0) {
    cout << "NO\n";
    return;
  }

  c = n / b;

  if (c <= b) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  cout << a << ' ' << b << ' ' << c << '\n';
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