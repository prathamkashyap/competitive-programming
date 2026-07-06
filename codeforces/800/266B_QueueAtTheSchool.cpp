#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int main(){
  int n=0, t=0;
  cin >> n >> t;
  string s;
  cin >> s;

  while (t--) {
    for (int i=0; i<=n; i++) {
      if (s[i] == 'B' && s[i+1] == 'G') {
        swap(s[i], s[i+1]);
        i++;
      }
    }
  }
  cout << s;


  return 0;
}