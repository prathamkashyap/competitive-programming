#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  getline(cin, str);

  bool alphabets[26] = {};

  for (int i=1; i < str.length() - 1; i++) {
    if (str[i] != ' ' && str[i] != '{' && str[i] != '}' && str[i] != ',') {
      alphabets[str[i]-97] = true;
    }
  }
  
  int count = 0;

  for (int i=0 ; i<26; i++) {
    if (alphabets[i] == true)
      count += 1;
  }

  cout << count << endl;
  return 0;
}