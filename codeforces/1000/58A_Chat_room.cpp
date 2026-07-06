#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    string target = "hello";
    int j = 0;  // Index for target string
    
    for (int i = 0; i < s.length(); i++) {
        if (j < target.length() && s[i] == target[j]) {
            j++;
        }
    }
    
    if (j == 5) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    return 0;
}
