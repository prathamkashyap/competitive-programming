#include <iostream>
#include <vector>

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

    vector<int> a(n);
    for (int i=0; i<n; i++)
      cin >> a[i];

    int l = 0, r = n-1;
    ll leftSum = 0, rightSum = 0;
    int ans = 0;

    while (l <= r) {
      if (leftSum <= rightSum) {
        leftSum += a[l++];
      } else {
        rightSum += a[r--];
      }
      
      if (leftSum == rightSum)
        ans = l + (n - 1 - r);
    }

    cout << ans << '\n';

  }
  
  return 0;
}