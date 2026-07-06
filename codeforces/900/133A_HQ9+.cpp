#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string p;
    if (!(cin >> p)) return 0;
    
    for (char c : p) {
        if (c == 'H' || c == 'Q' || c == '9') {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
