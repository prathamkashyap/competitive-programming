#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void checkBigrams() {
  int aS;
  cin >> aS;
  
  bool threeOrMore = false;
  int repeatedLetters = 0;

  for (int i=0; i<aS; i++) {
    int freq;
    cin >> freq;

    if (freq >= 3)
      threeOrMore = true;

    if (freq >= 2)
      repeatedLetters++;
  }

  if (threeOrMore || repeatedLetters >= 2) 
    cout << "YES\n";
  else
    cout << "NO\n"; 
}

int main(){
  int t;
  cin >> t;

  while (t--) {
    checkBigrams();
  }

  return 0;
}