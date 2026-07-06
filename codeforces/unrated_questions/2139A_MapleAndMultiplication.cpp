#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a%b);
}
int main(){
  int t;
  cin >> t;
  int a, b;
  int factor = 0;

  for(int i=0; i < t; i++) {
    cin >> a >> b;
    factor = gcd(a,b);
    if (a == b) {
      cout << 0 << endl;
    }
    else if (a == factor || b == factor) {
      cout << 1 << endl;
    }
    else {
      cout << 2 << endl;
    }
  }
  return 0;
}