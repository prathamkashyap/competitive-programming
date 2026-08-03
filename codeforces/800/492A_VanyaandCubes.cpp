// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   int n;
//   cin >> n;

//   int level = 0;
//   int used = 0;

//   while (used + (level + 1) * (level + 2) / 2 <= n) {
//     level++;
//     used += level * (level + 1) / 2;
//   }

//   cout << level << "\n";
//   return 0;
// }


#include <iostream>

using namespace std;

int main() {
  int totalCubes;
  cin >> totalCubes;

  int currentLevel = 0;

  for (int layer=1; layer<=10000; layer++) {
    currentLevel = layer*(layer+1)/2;

    if (totalCubes < currentLevel) {
      cout << layer - 1;
      break;
    }

    totalCubes -= currentLevel;
  }
  return 0;
}