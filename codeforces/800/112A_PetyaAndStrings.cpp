#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  string a = "";
  string b = "";
  cin >> a >> b;
  int n = a.length();
  bool flag = 1;

  
  for (int i=0; i<n; i++) {
    if (a[i] > 90) a[i]-=32;
    if (b[i] > 90) b[i]-=32;

    if (a[i] > b[i]){
      cout << 1;
      flag = 0;
      break;
    }

    else if(a[i] < b[i]){
      cout << -1;
      flag = 0;
      break;
    } 
  }
  if (flag == 1)  cout << 0;
  return 0;
}