#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';

        if (i == 0 && d == 9)
            continue;

        if (d >= 5)
            s[i] = char('0' + (9 - d));
    }

    cout << s << '\n';

    return 0;
}