#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        // Count dashes and underscores
        long long dash = 0, underscore = 0;
        for (char c : s) {
            if (c == '-') dash++;
            else underscore++;
        }
        
        // Need at least 2 dashes and 1 underscore
        if (dash < 2 || underscore == 0) {
            cout << 0 << '\n';
            continue;
        }
        
        // Optimal split: divide dashes as evenly as possible
        long long left = dash / 2;
        long long right = dash - left;
        
        // Answer is left * underscore * right
        cout << left * underscore * right << '\n';
    }
    
    return 0;
}
