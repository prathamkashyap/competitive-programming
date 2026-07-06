#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int n, m;
  for(int i=0; i < t; i++) {
    cin >> n >> m;
    vector<int> producedCakes (n);
    for (int i=0; i<n; i++) {
      cin >> producedCakes[i];
    }
    sort(producedCakes.begin(), producedCakes.end());
    
    int maxCakeCount = 0;
    for (int j = n - 1; j >= n - m; j--) {
      maxCakeCount += producedCakes[j];
    }


    cout << maxCakeCount << endl;
  }
  return 0;
}