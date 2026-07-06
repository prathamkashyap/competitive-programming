#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // The sum of difference array = a[n-1] - a[0] (telescoping)
        // We want to minimize |a[n-1] - a[0]|
        
        // Handle first and last elements to minimize absolute difference
        if (a[0] == -1 && a[n-1] == -1) {
            // Both are blank, set both to 0 for minimum |0 - 0| = 0
            a[0] = 0;
            a[n-1] = 0;
        } else if (a[0] == -1) {
            // First is blank, set it equal to last for |0| = 0
            a[0] = a[n-1];
        } else if (a[n-1] == -1) {
            // Last is blank, set it equal to first for |0| = 0
            a[n-1] = a[0];
        }
        // If both are set, we can't change them
        
        // For lexicographically smallest, fill remaining blanks with 0
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = 0;
            }
        }
        
        // Calculate the minimum absolute sum
        long long minSum = abs(a[n-1] - a[0]);
        
        // Output
        cout << minSum << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i];
            if (i < n - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}