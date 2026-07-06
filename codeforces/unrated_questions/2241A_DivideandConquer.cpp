// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   int t;
//   cin >> t;

//   while (t--) {
//     int x, y, z;
//     cin >> x >> y;

//     z = 2;
//     while(x >= y) {
//       if (x == y) {
//         cout << "YES" << endl;
//         return 0;
//       }
//       if (x % z == 0)
//         x = x/(z++);
//     }
//     cout << "NO" << endl;
//   }
//   return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if (x % y == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}