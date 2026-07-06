// My Solution
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int coins=0;
  cin >> coins;
  
  int totalMoney = 0;
  vector<int> deno(coins);
  for (int i=0; i<coins; i++) {
    cin >> deno[i];
    totalMoney += deno[i];
  }

  int myMoney = 0;
  sort(deno.begin(), deno.end());

  int i=0, totalMoney2 = totalMoney, bigCoins = 0;
  while ((myMoney <= totalMoney) && (bigCoins <= totalMoney2)) {
    myMoney += deno[i];
    totalMoney -= deno[i];
    bigCoins += deno[coins-i-1];
    totalMoney2 -= deno[coins-i-1];
    i++;
  }

  cout << i;

  return 0;
}

// AI Solution
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     vector<int> coins(n);
//     int total = 0;
//     for (int i = 0; i < n; i++) {
//         cin >> coins[i];
//         total += coins[i];
//     }

//     sort(coins.rbegin(), coins.rend()); // Sort descending order

//     int mySum = 0, count = 0;
//     for (int coin : coins) {
//         mySum += coin;
//         total -= coin;
//         count++;
//         if (mySum > total) {
//             cout << count << "\n";
//             break;
//         }
//     }

//     return 0;
// }
