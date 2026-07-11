#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;

  while (t--) {
    int candies;
    cin >> candies;

    int split = candies/2;
    
    if (candies % 2 == 0)
      cout << split-1 << endl;
    
    else 
      cout << split << endl;
  }

  return 0;
}