#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        int zeros = 0;

        for (char c : s) {
            if (c == '0')
                zeros++;
        }

        if (zeros == 1)
            cout << "BOB\n";
        else if (zeros % 2 == 1)
            cout << "ALICE\n";
        else
            cout << "BOB\n";
    }

    return 0;
}