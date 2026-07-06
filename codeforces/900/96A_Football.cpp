#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    if (cin >> s) {
        if (s.find("0000000") != string::npos || s.find("1111111") != string::npos)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
