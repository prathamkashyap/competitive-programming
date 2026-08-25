#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for (int i=0; i<n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    // Prefix sum
    vector<long long> prefix(n+1, 0);

    for (int i=0; i<n; i++) {
      prefix[i+1] = prefix[i] + a[i];
    }

    long long answer = 0;

    for (int i=0; i<=k; i++) {
      long long current = prefix[n-k+i] - prefix[2*i];
      answer = max(answer, current);
    }

    cout << answer << '\n';
  }

  return 0;
}