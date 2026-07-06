#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        
        // Count definite operations
        int top0 = 0;    // Count of '0' (remove from top)
        int bot1 = 0;    // Count of '1' (remove from bottom)
        int any2 = 0;    // Count of '2' (remove from either)
        
        for (char c : s) {
            if (c == '0') top0++;
            else if (c == '1') bot1++;
            else any2++;
        }
        
        // After definite operations:
        // Cards 1 to top0 are definitely removed from top
        // Cards (n - bot1 + 1) to n are definitely removed from bottom
        
        // For the '2' operations, we consider best/worst cases:
        // Best case for card i: remove as many from opposite end as possible
        // Worst case for card i: remove from this end
        
        string result(n, '?');
        
        for (int i = 1; i <= n; i++) {
            // Check if definitely removed
            if (i <= top0 || i > n - bot1) {
                result[i - 1] = '-';
                continue;
            }
            
            // Card is in range [top0 + 1, n - bot1]
            // Check if it survives all possible scenarios with '2' operations
            
            // Distance from top boundary: i - top0
            // Distance from bottom boundary: (n - bot1) - i + 1
            
            int distFromTop = i - top0;
            int distFromBottom = (n - bot1) - i + 1;
            
            // Card survives if it's beyond reach of any2 operations from both ends
            if (distFromTop > any2 && distFromBottom > any2) {
                result[i - 1] = '+';
            } else {
                result[i - 1] = '?';
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}