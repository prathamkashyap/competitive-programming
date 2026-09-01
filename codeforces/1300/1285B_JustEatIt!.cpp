#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long long> a(n);

    long long total = 0;

    for (int i=0; i<n; i++) {
      cin >> a[i];
      total += a[i];
    }

    long long current = a[0];
    long long best = a[0];

    for (int i=1; i<n-1; i++) {
      current = max(a[i], current + a[i]);
      best = max(best, current);
    }

    if (best >= total) {
      cout << "NO\n";
      continue;
    }

    current = a[n-1];
    best = a[n-1];

    for (int i=n-2; i>0; i--) {
      current = max(a[i], current + a[i]);
      best = max(best, current);
    }

    if (best >= total) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }

  return 0;
}