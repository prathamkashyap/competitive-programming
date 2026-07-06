// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// // bool isGoodNumber(long long n) {
// //     string s = to_string(n);

// //     char first = s[0];
// //     char second = '#';

// //     for (char c : s) {
// //         if (c != first && second == '#')
// //             second = c;

// //         if (c != first && c != second)
// //             return false;
// //     }

// //     return true;
// // }

// // bool isGoodNumber(long long n) {
// //     string s = to_string(n);

// //     unordered_set<char> st;

// //     for (char c : s)
// //         st.insert(c);

// //     return st.size() <= 2;
// // }

// bool isGoodNumber(long long n) {
//     string s = to_string(n);

//     char first = s[0];
//     char second = '#';

//     for (char c : s) {
//         if (c != first && second == '#')
//             second = c;

//         if (c != first && c != second)
//             return false;
//     }

//     return true;
// }

// int main(){
//   int t;
//   cin >> t;

//   // while (t--) {
//   //   int x;
//   //   cin >> x;

//   //   for (long long y=2; y<2*pow(10, 9); y++) {
//   //     if (isGoodNumber(y) && isGoodNumber(x*y)) {
//   //       cout << y << endl;
//   //       break;
//   //     }
//   //   }
//   // }

//   vector<long long> goodNumbers;

//   while (t--) {
//       int x;
//       cin >> x;

//       for (long long y : goodNumbers) {
//           if (isGoodNumber(x * y)) {
//               cout << y << '\n';
//               break;
//           }
//       }
//   }
//   return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        int y = 1;

        while (x > 0) {
            y *= 10;
            x /= 10;
        }

        cout << y + 1 << '\n';
    }

    return 0;
}