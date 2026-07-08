#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  int cnt = 1;
  for (int i=0; i<s.size(); i++) {
    if (s[i] == s[i-1]) {
      cnt++;
    }
    else {
      cnt = 1;
    }

    if (cnt >= 7) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
  return 0;
}