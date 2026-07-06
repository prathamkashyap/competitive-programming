#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isValid(int r, int k) {
    // No goals at all is valid
    if (r == 0 && k == 0) return true;
    
    // Only one team scores - can have at most 2 goals
    if (r == 0) return k <= 2;
    if (k == 0) return r <= 2;
    
    // Both teams score - difference can't be more than 1
    // This ensures we can always interleave to avoid 3 consecutive
    return abs(r - k) <= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        // Check first half
        bool firstValid = isValid(a, b);
        
        // Check second half  
        bool secondValid = isValid(c - a, d - b);
        
        cout << (firstValid && secondValid ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
