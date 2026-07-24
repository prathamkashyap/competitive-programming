#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    cin >> n;

    reverse(n.begin(), n.end());

    for (char c : n) {
        int d = c - '0';

        if (d >= 5) {
            cout << "-O|";
            d -= 5;
        } else {
            cout << "O-|";
        }

        for (int i = 0; i < 5; i++) {
            if (i == d)
                cout << '-';
            else
                cout << 'O';
        }

        cout << '\n';
    }

    return 0;
}