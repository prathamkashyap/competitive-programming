#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char dir;
    cin >> dir;

    string s;
    cin >> s;

    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

    for (char c : s) {
        int pos = keyboard.find(c);
        if (dir == 'R')
            cout << keyboard[pos - 1];
        else
            cout << keyboard[pos + 1];
    }

    cout << '\n';
    return 0;
}