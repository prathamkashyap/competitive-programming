#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int k, n, w;
  cin >> k >> n >> w;

  for (int i=1; i<=w; i++) {
    n -= k*i;
  }

  if (n < 0) {
    cout << abs(n) << endl;
  }
  else {
    cout << 0 << endl;
  }
  return 0;
}