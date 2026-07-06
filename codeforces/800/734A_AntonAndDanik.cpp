#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;

  cin >> n;
  cin >> s;

  // int countA = 0, countD = 0;

  // for (int i=0; i<n; i++) {
  //   if (s[i] == 'A') countA++;
  //   else countD++;
  // }

  // (countA > countD) ? cout << "Anton" : (countA == countD) ? cout << "Friendship" : cout << "Danik";

  int A_wins = 0;
  for (int i=0; i<n; i++) {
    if (s[i] == 'A')
      A_wins++;
    else  A_wins--;
  }
  if (A_wins > 0) cout << "Anton";
  else if (A_wins == 0) cout << "Friendship";
  else cout << "Danik";
  return 0;
}