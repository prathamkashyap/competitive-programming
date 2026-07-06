#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  // vector<int> volumes(n);
  float volume = 0;
  float avg = 0;

  for(int i=0; i < n; i++) {
    // cin >> volumes[i];
    cin >> volume;
    avg += volume;
  }

  cout << avg/n;
  return 0;
}