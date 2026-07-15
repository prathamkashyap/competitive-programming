#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int a[5];
  cin >> a[1] >> a[2] >> a[3] >> a[4];

  string s;
  cin >> s;

  int ans = 0;

  for (char c : s) {
    ans += a[c-'0'];
  }

  cout << ans;
  return 0;
}