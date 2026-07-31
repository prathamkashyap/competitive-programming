#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> position(n+1);

  for (int i=1; i<=n; i++) {
    int x;
    cin >> x;
    position[x] = i;
  }

  int m;
  cin >> m;

  ll vasya = 0;
  ll petya = 0;

  while (m--) {
    int x;
    cin >> x;

    vasya += position[x];
    petya += n - position[x] + 1;
  }

  cout << vasya << ' ' << petya << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}