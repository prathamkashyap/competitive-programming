#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int apples;
  cin >> apples;

  int n, m;
  cin >> n >> m;

  vector<bool> likes(apples + 1, false);

  for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      likes[x] = true;
  }

  for (int type = 1; type <= apples; type++) {
      if (likes[type])
          cout << 1 << " ";
      else
          cout << 2 << " ";
  }
  return 0;
}