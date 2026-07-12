#include<bits/stdc++.h>
using namespace std;

int main(){
  int tvSets, canCarry;
  cin >> tvSets >> canCarry;
  vector<int> prices(tvSets);
  
  for (int i=0; i<tvSets; i++){ 
    cin >> prices[i];
  }  

  sort(prices.begin(), prices.end());
  
  int maxProfit = 0;
  for (int i=0; i<canCarry; i++) {
    if (prices[i] > 0) break;
    maxProfit += prices[i];
  }

  cout << maxProfit*(-1);

  return 0;
}