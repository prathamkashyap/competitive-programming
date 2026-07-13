/*
Complexity Analysis
Time Complexity

    First window: O(k)

    Sliding through remaining elements: O(n-k)

Overall:

O(n)

Space Complexity

Input array:

O(n)

Extra variables:

O(1)
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> h(n);

  for (int i=0; i<n; i++){ 
    cin >> h[i];
  }

  long long sum = 0;

  for (int i=0; i<k; i++) {
    sum += h[i];
  }

  long long minSum = sum;
  int ans = 1;

  for (int i=k; i<n; i++) {
    sum += h[i];
    sum -= h[i-k];

    if (sum < minSum) {
      minSum = sum;
      ans = i-k+2;
    }
  }

  cout << ans << '\n';
  return 0;
}