// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   int t;
//   cin >> t;
//   int n, s;
//   for(int i=0; i < t; i++) {
//     cin >> n >> s;
//     vector<int> v(n);

//     int sum = 0;
//     for (int i=0; i<n; i++){
//       cin >> v[i];
//       sum += v[i];
//     }
    
//     if (sum == s) cout << -1;
    
//   }
//   return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canReachSum(const vector<int>& arr, int s) {
    int n = (int)arr.size();
    if (arr[0] > s) return false;

    vector<vector<bool>> visited(n, vector<bool>(s + 1, false));
    queue<pair<int,int>> q;
    q.push({0, arr[0]});
    visited[0][arr[0]] = true;

    while (!q.empty()) {
        auto [pos, sum_curr] = q.front(); q.pop();

        if (pos == n - 1 && sum_curr == s)
            return true;

        if (pos > 0) {
            int new_sum = sum_curr + arr[pos - 1];
            if (new_sum <= s && !visited[pos - 1][new_sum]) {
                visited[pos - 1][new_sum] = true;
                q.push({pos - 1, new_sum});
            }
        }

        if (pos < n - 1) {
            int new_sum = sum_curr + arr[pos + 1];
            if (new_sum <= s && !visited[pos + 1][new_sum]) {
                visited[pos + 1][new_sum] = true;
                q.push({pos + 1, new_sum});
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        vector<int> arr(n);
        for (int &x : arr) cin >> x;

        sort(arr.begin(), arr.end());

        bool found = false;
        do {
            if (!canReachSum(arr, s)) {
                for (int x : arr) cout << x << " ";
                cout << "\n";
                found = true;
                break;
            }
        } while (next_permutation(arr.begin(), arr.end()));

        if (!found) cout << -1 << "\n";
    }
    return 0;
}
