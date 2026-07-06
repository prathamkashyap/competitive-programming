#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int a, b;
  for(int i=0; i < t; i++) {
    cin >> a >> b;
    // int cnt = 0;
    // while (a % b != 0) {
    //   cnt++;
    //   a++;
    // }
    if (a >= b) {
      if (a%b == 0) {
        cout << 0 << endl;
        continue;
      }
      cout << b - (a%b) << endl;
    }
    else {
      cout << b-a << endl;
    }
  }
  return 0;
}