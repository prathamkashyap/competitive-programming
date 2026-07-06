#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int x;
  cin >> x;
  int steps = 1;
  if (x >= 5) {
    steps += x/5;
  }
  if (x % 5 == 0) steps--;
  cout << steps;
  return 0;
}