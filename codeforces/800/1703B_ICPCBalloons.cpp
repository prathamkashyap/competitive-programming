#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int n, curr;
  string s;
  
  for(int i=0; i < t; i++) {
    vector<int> loons(26,2);
    int score=0;
    cin >> n;
    cin >> s;
    for (int i=0; i<n; i++) {
      curr = s[i] - 'A';
      score += loons[curr];
      if (loons[curr] == 2) loons[curr]--;
    }
    cout << score << endl;
  }
  return 0;
}