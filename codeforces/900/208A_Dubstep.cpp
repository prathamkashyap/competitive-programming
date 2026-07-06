#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    bool first = true;
    
    for (int i = 0; i < s.length(); i++) {
        // Check if current position starts with "WUB"
        if (i + 2 < s.length() && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') {
            // Add space before next word (if not first word)
            if (!first) {
                cout << " ";
            }
            // Skip "WUB"
            i += 2;
        }
        else {
            cout << s[i];
            first = false;
        }
    }
    
    cout << endl;
    return 0;
}
