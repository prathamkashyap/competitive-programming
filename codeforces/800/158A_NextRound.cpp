#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n=0, k=0;
  cin >> n >> k;
  
  int cnt=0;
  vector<int> v(n);
  for (int i=0; i<n; i++) {
    cin >> v[i];
  }

  for (int j=0; j<n; j++) {
    if (v[j] >= v[k-1] && v[j]>0) cnt++;
  }
  cout << cnt;
  return 0;
}