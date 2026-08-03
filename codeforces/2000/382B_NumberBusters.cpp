#include <iostream>
#include <vector> 

using namespace std;
using ll = long long;

ll a, b, w, x, c;

bool check(ll t) {
  ll borrow = 0;

  if (t * x > b) {
    borrow = (t * x - b + w - 1) / w;
  }

  return a - borrow >= c - t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a >> b >> w >> x >> c;

  ll lo = 0;
  ll hi = 1e18;

  while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;

    if (check(mid)) {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }

  cout << lo << '\n';

  return 0;
}