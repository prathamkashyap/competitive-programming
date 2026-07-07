#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  for(int i=0; i < t; i++) {
    long long n;
    cin >> n;

    int twos = 0, threes = 0;

    while (n % 2 == 0) {
      twos++;
      n /= 2;
    }

    while (n % 3 == 0) {
      threes++;
      n /= 3;
    }

    if (n != 1 || twos > threes) {
      cout << -1 << '\n';
    }
    else {
      cout << 2 * threes - twos << '\n';
    }
    
  }
  return 0;
}