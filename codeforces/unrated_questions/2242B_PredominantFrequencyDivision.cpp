#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void divideArray() {
  int length;
  cin >> length;

  vector<int> values(length);
  for (int i=0; i<length; i++) {
    cin >> values[i];
  }

  vector<int> prefLeft(length), prefMid(length);

  int balanceLeft = 0;
  int balanceMid = 0;

  for (int i=0; i<length; i++){
    if (values[i] == 1) {
      balanceLeft++;
    }
    else
      balanceLeft--;

    prefLeft[i] = balanceLeft;

    if (values[i] == 3)
      balanceMid--;
    else
      balanceMid++;

    prefMid[i] = balanceMid;
  }
  
  int minimumPrefMid = INT_MAX;

  for (int split = 1; split <= length-2; split++) {
    int previous = split - 1;

    if (prefLeft[previous] >= 0) {
      minimumPrefMid = min(minimumPrefMid, prefMid[previous]);
    }

    if (minimumPrefMid <= prefMid[split]) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";

}

int main(){
  int t;
  cin >> t;

  while (t--) {
    divideArray();
  }
  return 0;
}