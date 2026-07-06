#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t=0;
  cin >> t;
  while (t--) {
    string s = "";
    cin >> s;
    int size = s.size();
    if (size > 10){
      cout << s[0] << size-2 << s[size-1] << endl;
    }
    else{
      cout << s << endl;
    }
  }
  return 0;
}