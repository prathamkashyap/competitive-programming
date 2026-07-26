#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    ll sum = 0;

    for (int i=0; i<n; i++) {
      ll x;
      cin >> x;
      sum += x;
    }

    ll root = sqrt(sum);

    if (root * root == sum)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}