#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
  int t=0;
  cin >> t;

  while(t--) {
    int n=0, k=0;
    cin >> n >> k;

    int day=0;
    int canGo=0, times=0;
    for (int i=0; i<n; i++) {
      cin >> day;
      if (day == 0) canGo++;
      else canGo=0;
      if (canGo == k) {
        times++;
        canGo=-1;
      }
    }
    cout << times << endl;

    // int canGo=0, ans=0;
    // vector<int> v(n);
    // for(int i=0; i<n; i++) {
    //   cin >> v[i];
    //   if (v[i]==0) canGo++;
    //   else canGo = 0;
    //   if(canGo == k) {
    //     ans+=1;
    //     canGo=0;
    //   }
    // }
    // cout << ans << endl;
  }
  return 0;
}


// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin >> t;
//     while(t--) {
//         int n, k;
    //     cin >> n >> k;
    //     vector<int> days(n);
        
    //     for(int i = 0; i < n; i++) {
    //         cin >> days[i];
    //     }
    //     int times = 0;
    //     int i = 0;

    //     while(i <= n - k) {
    //         bool canHike = true;
    //         for(int j = i; j < i + k; j++) {
    //             if(days[j] != 0) {
    //                 canHike = false;
    //                 break;
    //             }
    //         }
            
    //         if(canHike) {
    //             times++;
    //             i += k + 1;
    //         } else {
    //             i++;
    //         }
    //     }
        
    //     cout << times << endl;
    // }
//     return 0;
// }