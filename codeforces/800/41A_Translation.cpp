#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  string s, t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();

  bool flag = false;
  if (n == m) {
    flag = true;
    for (int i=0; i<n; i++) {
      if (s[i] == t[m-i-1]) {
        continue;
      }
      flag = false;
      break;
    }
  }
  if (flag == true) cout << "YES";
  else cout << "NO";
  return 0;
}