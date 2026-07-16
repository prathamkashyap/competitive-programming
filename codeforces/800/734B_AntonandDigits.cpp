#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k2, k3, k5, k6;
  cin >> k2 >> k3 >> k5 >> k6;

  // int maxSum=0;

  // while (k2 > 0 && k5 > 0 && k6 > 0) {
  //   maxSum += 256;
  //   k2--;
  //   k5--;
  //   k6--;
  // }

  // while (k2 > 0 && k3 > 0) {
  //   maxSum += 32;
  //   k2--;
  //   k3--;
  // }
  
  // cout << maxSum << '\n';

  int x = min({k2, k5, k6});
  int ans = x * 256;

  k2 -= x;

  int y = min(k2, k3);
  ans += y * 32;

  cout << ans;

  return 0;
}