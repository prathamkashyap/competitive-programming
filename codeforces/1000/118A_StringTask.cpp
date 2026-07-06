#include<iostream>
#include<bits/stdc++.h>
#include <cctype>
using namespace std;

int main(){
  string s;
  cin >> s;

  for (int i=0; i<s.size(); i++) {

    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') continue;

    char c = tolower(s[i]);
    cout << '.' << c;
  }
  cout << "\n";
  return 0;
}