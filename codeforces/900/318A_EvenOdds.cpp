#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n, k;
  cin >> n >> k;

  long long odd_count = (n+1)/2;

  if (k <= odd_count) {
    cout << (k*2)-1 << endl;
  }
  else {
    cout << (k-odd_count)*2 << endl;
  }
  return 0;
}