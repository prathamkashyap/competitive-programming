// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   int n, m;
//   cin >> n >> m;

//   int ops = 0;
//   while (n < m) {
//     n *= 2;
//     ops++;
//   }

//   while (n != m) {
//     n--;
//     ops++;
//   }


//   cout << ops;
//   return 0;
// }


/* 
Complexity

  Time: O(log m)

  Space: O(1)

*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ans = 0;

    while (m > n) {
        if (m % 2 == 0)
            m /= 2;
        else
            m++;

        ans++;
    }

    ans += (n - m);

    cout << ans;
}