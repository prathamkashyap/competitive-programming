#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }

  int l = 0;
  while (l + 1 < n && a[l] <= a[l+1]) {
    l++;
  }

  if (l == n - 1) {
    cout << "yes\n";
    cout << "1 1\n";
    return 0;
  }

  int r = l + 1;
  while (r + 1 < n && a[r] >= a[r+1])
    r++;

  reverse(a.begin() + l, a.begin() + r + 1);\
  
  for (int i=1; i<n; i++) {
    if (a[i] < a[i-1]) {
      cout << "no\n";
      return 0;
    }
  }

  cout << "yes\n";
  cout << l + 1 << ' ' << r + 1 << '\n';

  return 0;
}