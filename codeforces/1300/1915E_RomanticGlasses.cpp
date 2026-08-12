#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  set<ll> seen;
  seen.insert(0);

  ll prefixSum = 0;

  for (int i=1; i<=n; i++) {
    ll x;
    cin >> x;

    if (i % 2 == 1)
      prefixSum += x;
    else
      prefixSum -= x;

    if (seen.count(prefixSum)) {
      cout << "YES\n";

      for (int j=i+1; j<=n; j++) {
        cin >> x;
      }
      return;
    }
    seen.insert(prefixSum);
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