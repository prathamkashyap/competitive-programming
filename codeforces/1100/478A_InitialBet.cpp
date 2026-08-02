#include <iostream>
using namespace std;

int main() {
  int sum = 0, x;

  for (int i=0; i<5; i++) {
    cin >> x;
    sum += x;
  }

  if (sum == 0 || sum % 5 != 0) {
    cout << -1;
  }
  else {
    cout << sum / 5;
  }

  return 0;
}