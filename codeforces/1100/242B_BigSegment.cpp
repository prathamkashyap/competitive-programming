#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  vector<pair<int, int>> seg(n);

  int L = INT_MAX, R = INT_MIN;

  for (int i=0; i<n; i++) {
    cin >> seg[i].first >> seg[i].second;
    L = min(L, seg[i].first);
    R = max(R, seg[i].second);
  }

  for (int i=0; i<n; i++) {
    if (seg[i].first == L && seg[i].second == R) {
      cout << i+1 << '\n';
      return 0;
    }
  }

  cout << -1 << '\n';
  return 0;
}