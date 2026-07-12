#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;

  char curr = 'a';
  int ans = 0;

  for(char target : s) {
    int diff = abs(curr - target);
    ans += min(diff, 26 - diff);
    curr = target;
  }

  cout << ans;
  return 0;
}