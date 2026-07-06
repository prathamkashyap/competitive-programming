#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        
        // Count presence of each value in [0, k-1]
        set<int> present;
        int k_count = 0;
        
        for (int x : a) {
            if (x < k) {
                present.insert(x);
            } else if (x == k) {
                k_count++;
            }
        }
        
        int missing_count = k - (int)present.size();
        
        cout << max(missing_count, k_count) << '\n';
    }
    
    return 0;
}
