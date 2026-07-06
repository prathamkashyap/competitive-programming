#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int n;
  for(int i=0; i < t; i++) {
    cin >> n;
    if (n%2 == 0){
      int a = 2;
      for (int i=0; i<n/2; i++) {
        if (a>2) a++;
        cout << -1 << " " << a << " ";
      }
    }
    else {
      for (int i=0; i<(n-1)/2; i++) {
        cout << -1 << " " << 3 << " ";
      }
      cout << -1;
    }
    cout << endl;
  }
  return 0;
}

