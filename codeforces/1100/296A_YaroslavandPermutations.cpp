#include <iostream>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<int, int> freq;
  int mx = 0;

  for (int i=0; i<n; i++) {
    int x;
    cin >> x;

    mx = max(mx, ++freq[x]);
  }

  if (2 * mx <= n + 1)
    cout << "YES\n";

  else 
    cout << "NO\n";
  return 0;
}