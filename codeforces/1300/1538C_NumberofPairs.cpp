#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll countPairs(const vector<ll>& a, ll x) {
  int left = 0;
  int right = a.size() - 1;

  ll count = 0;

  while (left < right) {
    if (a[left] + a[right] <= x) {
      count += right - left;
      left++;
    }
    else {
      right--;
    }
  }

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    ll l, r;

    cin >> n >> l >> r;

    vector<ll> a(n);

    for (ll&x : a)
      cin >> x;

    sort(a.begin(), a.end());

    cout << countPairs(a, r) - countPairs(a, l-1) << '\n';
  }

  return 0;
}