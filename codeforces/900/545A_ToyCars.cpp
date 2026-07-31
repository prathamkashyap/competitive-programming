#include <iostream>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> answer;

  for (int i=1; i<=n; i++) {
    bool good = true;

    for (int j=1; j<=n;j++) {
      int x;
      cin >> x;

      if (x == 1 || x == 3) {
        good = false;
      }
    }

    if (good) {
      answer.push_back(i);
    }
  }

  cout << answer.size() << '\n';

  for (int car : answer) {
    cout << car << ' ';
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}