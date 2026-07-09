#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int s;
  int count1 = 0, count2 = 0, count3 = 0, minTaxis = 0;
  for (int i=0; i<n; i++) {
    cin >> s;
    if (s == 1) count1++;
    else if (s == 2) count2++;
    else if (s == 3) count3++;
    else minTaxis++;
  }

  while (count1 != 0 && count3 != 0) {
    minTaxis++;
    count3--;
    count1--;
  }

  if (count3 > 0)
    minTaxis += count3;

  minTaxis += (int)(count2 / 2);
  count2 %= 2;

  if (count2 > 0) {
    minTaxis++;
    count1 = max(0, count1 - 2);
  }

  minTaxis += (count1 + 3) / 4;

  cout << minTaxis;

  return 0;
}