// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   long long n = 0;
//   long long f = 0;

//   cin >> n;
//   for (long long i=1; i<=n; i++) {
//     // f += pow(-1, i)*i;
//     if (i%2 != 0) f -= i;
//     else f += i;
//   }
//   cout << f; 
    
//   return 0;
// }

// Correct Solution 1
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n % 2 == 0) {
        cout << n / 2 << "\n";
    } else {
        cout << -(n + 1) / 2 << "\n";
    }

    return 0;
}

// Correct Solution 2
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     long long n;
//     cin >> n;
//     if (n % 2 == 0) {
//         cout << n / 2 << "\n";
//     } else {
//         cout << -((n + 1) / 2) << "\n";
//     }
//     return 0;
// }

