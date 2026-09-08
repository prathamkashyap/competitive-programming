#include <iostream>

using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long n, k;
    cin >> n >> k;

    long long moves = k - 1;

    if (n % 2 == 1)
      moves += moves / (n/2);

    cout << moves % n + 1 << '\n';
  }

  return 0;
}