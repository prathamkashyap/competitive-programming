#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  int p, q;
  cin >> p;

  int index = 0;
  // bool levels[n] = {false};
  vector<bool> levels(n, false);

  for (int i=0; i<p; i++) {
    cin >> index;
    levels[index-1] = true;
  }

  cin >> q;
  for (int i=0; i<q; i++) {
    cin >> index;
    levels[index-1] = true;
  }

  for (int i=0; i<n; i++) {
    if (levels[i] == true) continue;
    cout << "Oh, my keyboard!" << endl;
    return 0;
  }
  cout << "I become the guy." << endl;
  return 0;
}