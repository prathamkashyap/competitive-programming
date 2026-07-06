#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isBalancedAfterRemoval(const string& s) {
  int n = s.size();
  int left = 0;
  int right = n-1;

  while (left < n && s[left] != '(') left++;
  while (right >= 0 && s[right] != ')') right--;

  if (left >= right) {
    return false;
  }

  int balance = 0;
  for (int i=0; i<n; i++) {
    if (i == left || i == right) continue;
    if (s[i] == '(') balance++;
    else balance--;
    if (balance < 0) return true;
  }

  return balance != 0;
}
int main(){
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
  
    cout << (isBalancedAfterRemoval(s) ? "YES\n" : "NO\n");
  }
  return 0;
}