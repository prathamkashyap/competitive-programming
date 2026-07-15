// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int mex(vector<int> &v2) {
//   int size = v2.size();
//   int ans = 0;
//   for (int i=0; i<size; i++) {
//     if (v2[i] > ans) return ans;
//     if (v2[i] == ans) ans++;
//   }
//   return ans;
// }

// int sum(vector<int> &v1) {
//   int size = v1.size();
//   int ans = 0;
//   for (int i=size-1; i>=0; i--) {
//     ans += v1[i];
//     if (v1[i] == 0) {
//       return ans;
//     }
//   }
//   return ans;
// }

// int main(){
//   int t=0;
//   int n=0;
//   while(t--) {
//     cin >> n;
//     vector<int> v(n);
//     for (int i=0; i<n; i++) {
//       cin >> v[i];
//     }
//     sort(v.begin(), v.end());
//     int score = sum(v) + mex(v);
//     cout << score << endl;
//   }
//   return 0;
// }



#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> S(n);
        int cnt0 = 0, sum = 0;
        for(int i = 0; i < n; ++i) {
            cin >> S[i];
            if(S[i] == 0) cnt0++;
            else sum += S[i];
        }
        cout << cnt0 + sum << endl;
    }
    return 0;
}
