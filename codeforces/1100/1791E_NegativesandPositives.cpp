#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    long long sum = 0;
    long negativeCount = 0;
    int minAbs = 1e9;

    for (int i=0; i<n; i++) {
      int x;
      cin >> x;

      if (x < 0) {
        negativeCount++;
      }

      int value = abs(x);

      sum += value;
      minAbs = min(minAbs, value);
    }

    if (negativeCount % 2 == 1)
      sum -= 2LL * minAbs;

    cout << sum << '\n';
  }

  return 0;
}
