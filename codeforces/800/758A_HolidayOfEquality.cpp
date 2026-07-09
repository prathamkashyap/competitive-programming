#include <iostream>
#include <vector>
using namespace std;

int welfareCharges(int n, vector<int> v) {
  int highestWelfare = 0, totalCharges = 0;

  for (int i=0; i<n; i++) {
    highestWelfare = max(v[i], highestWelfare);
  }

  for (int j=0; j<n; j++) {
    totalCharges += highestWelfare - v[j];
  }

  return totalCharges;
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n);

  for (int i=0; i<n; i++) {
    cin >> v[i];
  }

  cout << welfareCharges(n, v);
}