// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   int n;
//   cin >> n;

//   vector<int> prices(n);
//   for (int i=0; i<n; i++) {
//     cin >> prices[i];
//   }

//   int days;
//   cin >> days;

//   for (int j=0; j<days; j++) {
//     int budget;
//     cin >> budget;
    
//     int count = 0;

//     for (int k=0; k<n; k++) {
//       if (budget >= prices[k]) {
//         count++;
//       }
//     }
//     cout << count << endl;
//   }
//   return 0;
// }


/*

Complexity

Sorting:

O(n log n)

Each query:

O(log n)

Total:

O(n log n + q log n)

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> prices(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];

    sort(prices.begin(), prices.end());

    int q;
    cin >> q;

    while (q--) {
        int budget;
        cin >> budget;

        cout << upper_bound(prices.begin(), prices.end(), budget)
                - prices.begin()
             << '\n';
    }

    return 0;
}