/* TC: O(n^2)*/

// #include <iostream>
// #include <vector>

// using namespace std;

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   int t;
//   cin >> t;

//   while (t--) {
//     int n;
//     cin >> n;

//     vector<int> a(n+1);

//     for (int i=1; i<=n; i++) {
//       cin >> a[i];
//     }

//     int answer = 0;

//     for (int i=0; i<=n; i++) {
//       for (int j=i+1; j<=n; j++) {
//         if (a[i] * a[j] == i + j) {
//           answer++;
//         }
//       }
//     }

//     cout << answer << '\n';
//   }

//   return 0;
// }


/* TC: O(nlog(n))*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int answer = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = a[i] - i; j <= n; j += a[i]) {
                if (j > i && 1LL * a[i] * a[j] == i + j) {
                    answer++;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}