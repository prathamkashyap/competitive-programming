#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> original(n+1);
  vector<ll> sorted(n+1);

  for (int i = 1; i <= n; i++) {
    cin >> original[i];
    sorted[i] = original[i];
  }

  sort(sorted.begin() + 1, sorted.end());

  vector<ll> prefixOriginal(n + 1, 0);
  vector<ll> prefixSorted(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    prefixOriginal[i] = prefixOriginal[i - 1] + original[i];
    prefixSorted[i] = prefixSorted[i - 1] + sorted[i];
  }

  int m;
  cin >> m;

  while (m--) {
    int type, l, r;
    cin >> type >> l >> r;

    if (type == 1)
      cout << prefixOriginal[r] - prefixOriginal[l - 1] << '\n';
    else
      cout << prefixSorted[r] - prefixSorted[l - 1] << '\n';
  }

  return 0;
}