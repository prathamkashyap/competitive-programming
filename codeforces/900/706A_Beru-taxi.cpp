#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double a, b;
  cin >> a >> b;

  int n;
  cin >> n;

  double ans = 1e18;

  while (n--) {
    double x, y, v;
    cin >> x >> y >> v;

    double dist = sqrt((x-a) * (x-a) + (y-b) * (y-b));
    ans = min(ans, dist/v);
  }

  cout << fixed << setprecision(10) << ans << '\n';
  return 0;
}