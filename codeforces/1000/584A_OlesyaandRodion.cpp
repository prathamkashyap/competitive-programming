#include <iostream>

using namespace std;

using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  if (t == 10) {
    if (n == 1) {
      cout << -1 << '\n';
    } else {
      cout << 1;

      for (int i=1; i<n; i++)
        cout << 0;
      
      cout << '\n';
    }
  } else {
    cout << t;

    for (int i=1; i<n; i++) {
      cout << 0;
    }

    cout << '\n';
  }

  return 0;
}