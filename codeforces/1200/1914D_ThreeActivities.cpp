#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<pair<ll, int>> getTopThree(const vector<ll>& a) {
  vector<pair<ll, int>> values;

  for (int i=0; i<(int)a.size(); i++) {
    values.push_back({a[i], i});
  }

  sort(values.rbegin(), values.rend());

  if (values.size() > 3) {
    values.resize(3);
  }

  return values;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);

    for (ll& x : a) {
      cin >> x;
    }
    for (ll& x : b) {
      cin >> x;
    }
    for (ll& x : c) {
      cin >> x;
    }

    vector<pair<ll, int>> topA = getTopThree(a);
    vector<pair<ll, int>> topB = getTopThree(c);
    vector<pair<ll, int>> topC = getTopThree(b);

    ll answer = 0;

    for (auto [valueA, indexA] : topA) {
      for (auto [valueB, indexB] : topB) {
        for (auto [valueC, indexC] : topC) {

          if (indexA != indexB &&
              indexA != indexC &&
              indexB != indexC) {
                answer = max(answer, valueA + valueB + valueC);
          }
        }
      }
    }

    cout << answer << '\n';
  }
  return 0;
}