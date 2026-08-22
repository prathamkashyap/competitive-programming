#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);

    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    for (int i=0; i<n; i++) {
      cin >> b[i];
    }

    long long answer = 0;
    long long sum = 0;
    int maxB = 0;

    int limit = min(n, k);

    for (int i=0; i<limit; i++) {
      sum += a[i];
      maxB = max(maxB, b[i]);

      int remainingDays = k - (i + 1);

      long long total = sum + 1LL * remainingDays * maxB;

      answer = max(answer, total);
    }

    cout << answer << '\n';
  }

  return 0;
}