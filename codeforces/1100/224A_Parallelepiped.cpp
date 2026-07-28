#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll x, y, z;
  cin >> x >> y >> z;

  ll a = sqrt((x*z) / y);
  ll b = sqrt((x*y) / z);
  ll c = sqrt((y*z) / x);

  cout << 4 * (a + b + c) << '\n';
  return 0;
}