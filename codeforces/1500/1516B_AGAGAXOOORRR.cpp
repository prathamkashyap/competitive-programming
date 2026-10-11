#include <iostream>
#include <vector>
using namespace std;

bool solve() {
  int N;
  cin >> N;

  vector<int> a(N);
  int totalXor = 0;

  for (int i=0; i<N; i++) {
    cin >> a[i];
    totalXor ^= a[i];
  }

  if (totalXor == 0) {
    return true;
  }

  int currentXor = 0;
  int segments = 0;

  for (int i=0; i < N-1; i++) {
    currentXor ^= a[i];

    if (currentXor == totalXor) {
      segments++;
      currentXor = 0;

      if (segments == 2) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    cout << (solve() ? "YES\n" : "NO\n");
  }

  return 0;
}