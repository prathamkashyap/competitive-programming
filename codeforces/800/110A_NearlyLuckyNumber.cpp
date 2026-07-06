#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  
  long long cnt = 0, d = 0;
  while (n > 0) {
    d = n % 10;
    if (d == 4 || d == 7) {
      cnt++;
    }
     n /= 10;
  }

  if (cnt == 4 || cnt == 7) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}