#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        char c;
        string s;

        cin >> n >> c >> s;

        bool allEqual = true;

        for (char ch : s) {
            if (ch != c) {
                allEqual = false;
                break;
            }
        }

        if (allEqual) {
            cout << 0 << '\n';
            continue;
        }

        int position = -1;

        for (int i = n / 2 + 1; i <= n; i++) {
            if (s[i - 1] == c) {
                position = i;
                break;
            }
        }

        if (position != -1) {
            cout << 1 << '\n';
            cout << position << '\n';
        } else {
            cout << 2 << '\n';
            cout << n - 1 << " " << n << '\n';
        }
    }

    return 0;
}