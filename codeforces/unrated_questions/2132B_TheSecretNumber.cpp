// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int digit_count(long long n) {
//   if (n == 0) return 1;
//   if (n < 0) n = -n;
//   int cnt = 0;
//   while (n>0) {
//     n /= 10;
//     ++cnt;
//   }
//   return cnt;
// }

// int main(){
//   int t;
//   cin >> t;
//   int n;
//   for(int i=0; i < t; i++) {
//     cin >> n;
//     int size = digit_count(n);

//     if ((size % 2) == 0) {
//       cout << 0;
//     }
//     else {
//       /* As the number has an even number of digits, now we will be dividing it by its factors
//       For example: 999999999999999999 (18 times '9')
//       since its divisible by 1 we can spilt it in 9090909090909090 and 909090909090909 where the latter is a possible solution
//       for pairs of 2 characters each (2 nines and 2 zeroes) we can split it as 9900990099009900... which is not viable so rejected this pattern
//       for pairs of 3 character -> 999000999000999000 with 999000999000999 is acceptable and so on...
//       Help me code this logic up
//       */
//     }
//   }
//   return 0;
// }

// // Works but not on codeforces
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     if (!(cin >> t)) return 0;
//     while (t--) {
//         unsigned long long n;
//         cin >> n;
//         vector<unsigned long long> xs;

//         // Iterate k = 1..18 and test divisors d = 10^k + 1
//         __uint128_t p = 10; // 10^1
//         for (int k = 1; k <= 18; ++k) {
//             __uint128_t d128 = p + 1;     // d = 10^k + 1
//             if (d128 > (__uint128_t)n) break;
//             unsigned long long d = (unsigned long long)d128;
//             if (n % d == 0) {
//                 xs.push_back(n / d);
//             }
//             p *= 10; // move to 10^(k+1)
//         }

//         if (xs.empty()) {
//             cout << 0 << '\n';
//         } else {
//             sort(xs.begin(), xs.end());
//             xs.erase(unique(xs.begin(), xs.end()), xs.end());
//             cout << xs.size() << '\n';
//             for (size_t i = 0; i < xs.size(); ++i) {
//                 if (i) cout << ' ';
//                 cout << xs[i];
//             }
//             cout << '\n';
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    // Precompute powers of 10 up to 1e18 in unsigned long long
    static const unsigned long long POW10[] = {
        1ULL,
        10ULL,
        100ULL,
        1000ULL,
        10000ULL,
        100000ULL,
        1000000ULL,
        10000000ULL,
        100000000ULL,
        1000000000ULL,
        10000000000ULL,
        100000000000ULL,
        1000000000000ULL,
        10000000000000ULL,
        100000000000000ULL,
        1000000000000000ULL,
        10000000000000000ULL,
        100000000000000000ULL,
        1000000000000000000ULL
    }; // POW10[k] = 10^k, k in [0..18] [7]

    while (t--) {
        unsigned long long n;
        cin >> n;
        vector<unsigned long long> xs;

        // Test k = 1..18, divisor d = 10^k + 1
        for (int k = 1; k <= 18; ++k) {
            unsigned long long d = POW10[k] + 1ULL;   // fits in 64-bit for k<=18
            if (d > n) break;                         // no larger d can divide n
            if (n % d == 0ULL) {
                xs.push_back(n / d);
            }
        }

        if (xs.empty()) {
            cout << 0 << '\n';
        } else {
            sort(xs.begin(), xs.end());
            xs.erase(unique(xs.begin(), xs.end()), xs.end());
            cout << xs.size() << '\n';
            for (size_t i = 0; i < xs.size(); ++i) {
                if (i) cout << ' ';
                cout << xs[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
