#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  int n;
  for(int i=0; i < t; i++) {
    cin >> n;

    vector<string> player1(n);
    for (int i=0; i<n; i++) {
      cin >> player1[i];
    }
    vector<string> player2(n);
    for (int i=0; i<n; i++) {
      cin >> player2[i];
    }
    vector<string> player3(n);
    for (int i=0; i<n; i++) {
      cin >> player3[i];
    }

    vector<int> scores (3);
    for (int k=0; k<n; k++) {
      for (int i=0; i<n; i++) {
        if (player1[k] == player2[i]) {
          for (int j=0; j<n; j++) {
            if (player1[k] == player3[j]) {
              break;
            }
          }
        }
      }
    }
    


  }
  return 0;
}