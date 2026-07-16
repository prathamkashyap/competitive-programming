#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  // vector<int> queue(n);

  // for (int i=0; i<n; i++) {
  //   cin >> queue[i];
  // }

  // int entranceNumber = 0;

  // while (queue[entranceNumber] > 0) {
  //   for (int i=0; i<n; i++) {
  //     queue[i]--;
  //   }
  //   entranceNumber++;
  //   entranceNumber %= n;
  // }

  // cout << entranceNumber+1 << endl;

  long long bestTime = LLONG_MAX;
  int ans = 0;

  for (int i=0; i<n; i++) {
    long long x;
    cin >> x;

    long long t;

    if (x <= i)
      t = i;
    else
      t = i+((x-i+n-1)/n)*n;

    
    if (t < bestTime) {
      bestTime = t;
      ans = i;
    }
  }

  cout << ans + 1 << '\n';
  return 0;
}