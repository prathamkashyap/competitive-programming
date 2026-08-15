#include <iostream>

using namespace std;

using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;

  int answer = a;
  int stubs = a;

  while (stubs >= b) {
    int newCandles = stubs / b;

    answer += newCandles;

    stubs = newCandles + (stubs % b);
  }

  cout << answer << '\n';

  return 0;
}