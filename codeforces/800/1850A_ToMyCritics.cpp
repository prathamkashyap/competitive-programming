#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;

  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;

    if (x+y >= 10 || y+z >= 10 || x+z >=10) {
      cout << "YES" << endl;
    }
    else
      cout << "NO" << endl;

  }

  return 0;
}