#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, r;
  cin >> k >> r;

  int price = k;
  int shovels = 1;

  while (price % 10 != r) {
    if (price % 10 == 0)
      break;
  
    price += k;
    shovels++;

  }
  
  cout << shovels << '\n';
  return 0;
}