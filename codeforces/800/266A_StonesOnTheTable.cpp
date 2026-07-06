#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  string s;
  cin >> s;

  char curr = s[0];
  int cnt = 0;
  for (int i=1; i<s.size(); i++) {
    if (curr == s[i]) {
      cnt++;
    }
    if (curr != s[i]) {
      curr = s[i];
    }
  }
  cout << cnt;
  
  return 0;
}