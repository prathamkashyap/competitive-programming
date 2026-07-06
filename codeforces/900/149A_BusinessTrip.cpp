#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k;
  vector<int> a(12);
  for (int i=0; i<12; i++)
    cin >> a[i];

  sort(a.rbegin(), a.rend());
  int sum = 0, cnt = 0;
  for (int i=0; i<12; i++) {
    sum += a[i];
    cnt++;
  }
  if (sum < k) cout << -1 << "\n";
  else cout << cnt << "\n";
  return 0;
}