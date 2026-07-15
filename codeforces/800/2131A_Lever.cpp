// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   int t;
//   cin >> t;
//   int n;
//   for(int i=0; i < t; i++) {
//     cin >> n;
//     vector<int> a (n);
//     vector<int> b (n);
//     for (int i=0; i<n; i++) {
//       cin >> a[i];
//     }
//     for (int i=0; i<n; i++) {
//       cin >> b[i];
//     }

//     int iter = 0;
//     bool iCanDoMore = 1;

//     while (iCanDoMore) { // while I can update a[i]++
//       for (int i=0; i<n; i++){
//         bool iDidIt = 0;
//         if (!iDidIt) {
//           iter++;
//           for (int j=0; j<n; j++) {
//             if (a[i] > b[j]) {
//               a[i]--;
//               iDidIt = 1;
//               break;
//             }
//             iDidIt = 0;
//           }
//           if (iDidIt == 0) {
//             iCanDoMore = 0;
//             break;
//           }
          
//           // if (iDidIt == 0 && iCanDoMore == 0) {
//           //   cout << iter;
//           //   return 0;
//           // }
//         }

//         for (int j=0; j<n; j++) {
//           if (a[i] < b[j]) {
//             a[i]++;
//             break;
//           }
//         }
//       }
//     }
//     cout << iter << endl;
//   }
//   return 0;
// }


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        int iter = 0;
        while(true) {
            iter++;
            bool canDecrement = false;
            
            for(int i = 0; i < n; i++) {
                if(a[i] > b[i]) {
                    a[i]--;
                    canDecrement = true;
                    break;
                }
            }
            
            if(!canDecrement) {
                break;
            }
            
            for(int i = 0; i < n; i++) {
                if(a[i] < b[i]) {
                    a[i]++;
                    break;
                }
            }
        }
        
        cout << iter << endl;
    }
    return 0;
}