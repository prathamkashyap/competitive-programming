#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio;
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<int> nextDiff(n+1, -1);

    for (int i=1; i <= n; i++)
      cin >> a[i];

    nextDiff[n] = -1;

    for (int i = n-1; i >= 1; i--) {
      if (a[i] != a[i+1])
        nextDiff[i] = i + 1;
      
      else
        nextDiff[i] = nextDiff[i + 1];
    }

    int q;
    cin >> q;

    while (q--) {
      int l, r;
      cin >> l >> r;

      if (nextDiff[l] != -1 && nextDiff[l] <= r)
        cout << l << " " << nextDiff[l] << '\n';

      else
        cout << "-1 -1\n";
    }

    cout << '\n';
  }

  return 0;
}