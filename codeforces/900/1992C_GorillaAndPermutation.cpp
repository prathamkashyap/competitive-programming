#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> permutation;
        
        // First, place all numbers >= k in descending order
        for (int i = n; i >= k; i--) {
            permutation.push_back(i);
        }
        
        // Then, place all numbers between m+1 and k-1 (if any)
        for (int i = k - 1; i > m; i--) {
            permutation.push_back(i);
        }
        
        // Finally, place all numbers <= m in ascending order
        for (int i = 1; i <= m; i++) {
            permutation.push_back(i);
        }
        
        // Output the permutation
        for (int i = 0; i < n; i++) {
            cout << permutation[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}