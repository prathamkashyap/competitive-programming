#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t=0;
  cin >> t;
  int willSolve = 0;

  int a=0, b=0, c=0;
  while(t--) {
    cin >> a >> b >> c;
    if (a+b+c > 1) willSolve++;
  }
  cout << willSolve;
  return 0;
}