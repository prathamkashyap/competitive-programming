#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int firstMissing = 0;
  int secondMissing = 0;
  int x;

  // Original Array
  for (int i=0; i<n; i++) {
    cin >> x;
    firstMissing ^= x;
  }

  // Array after first removal
  for (int i=0; i<n-1; i++) {
    cin >> x;
    firstMissing ^= x;
    secondMissing ^= x;
  }

  // Array from second removal
  for (int i=0; i<n-2; i++) {
    cin >> x;
    secondMissing ^= x;
  }

  cout << firstMissing << '\n';
  cout << secondMissing << '\n';

  return 0;
}