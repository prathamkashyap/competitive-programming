#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;

    vector<int> k(n);
    vector<long long> c(m+1);

    for (int i=0; i<n; i++) {
      cin >> k[i];
    }

    for (int i=1; i<=m; i++) {
      cin >> c[i];
    }

    sort(k.rbegin(), k.rend());

    long long answer = 0;
    int j=1;

    for (int i=0; i<n; i++) {
      if (j <= k[i] && c[j] < c[k[i]]) {
        answer += c[j];
        j++;
      } else {
        answer += c[k[i]];
      }
    }

    cout << answer << '\n';
  }

  return 0;
}