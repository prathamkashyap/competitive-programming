#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int n, k;
  
  for(int i=0; i < t; i++) {
    bool flag = false;
    cin >> n >> k;
    vector<int> v(n);

    for (int i=0; i<n; i++) {
      cin >> v[i];
      if (v[i] == k) flag = true;
    }
    flag ? cout << "YES" << endl : cout << "NO" << endl;  }
  return 0;
}