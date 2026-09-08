#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> h(n);

    for (int &x : h) {
      cin >> x;
    }

    sort(h.begin(), h.end());

    if (n == 2) {
      cout << h[0] << " " << h[1] << '\n';
      continue;
    }

    int pos = 1;
    int minimumDifference = INT_MAX;

    for (int i=1; i<n; i++) {
      int difference = h[i] - h[i-1];

      if (difference < minimumDifference) {
        minimumDifference = difference;
        pos = i;
      }
    }

    for (int i=pos; i<n; i++) {
      cout << h[i] << " ";
    }

    for (int i=0; i<pos; i++) {
      cout << h[i] << " ";
    }
    
    cout << '\n';
  }

  return 0;
}