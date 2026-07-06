#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        // Strategy: sort the string in descending order
        // This ensures T's come before F's and N's, breaking FFT and NTT patterns
        sort(s.rbegin(), s.rend());
        
        cout << s << endl;
    }
    
    return 0;
}

/*
Alternative approach - more explicit control:

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool hasBadPattern(const string& s) {
    return s.find("FFT") != string::npos || s.find("NTT") != string::npos;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        // If already good, output as is
        if (!hasBadPattern(s)) {
            cout << s << endl;
            continue;
        }
        
        // Sort the string - this typically breaks the patterns
        sort(s.begin(), s.end());
        
        // If sorted version still has bad pattern (edge case)
        // Try reverse sort
        if (hasBadPattern(s)) {
            sort(s.rbegin(), s.rend());
        }
        
        cout << s << endl;
    }
    
    return 0;
}
*/