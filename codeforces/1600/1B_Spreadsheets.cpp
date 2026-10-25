#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

using ll = long long;

string columnToLetters(ll col) {
    string result;

    while (col > 0) {
        col--;
        result += char('A' + col % 26);
        col /= 26;
    }

    reverse(result.begin(), result.end());
    return result;
}

ll lettersToColumn(const string& letters) {
    ll col = 0;

    for (char c : letters) {
        col = col * 26 + (c - 'A' + 1);
    }

    return col;
}

void solve() {
    string s;
    cin >> s;

    // Detect RXCY format: R followed by digits, then C.
    if (s[0] == 'R' &&
        s.size() > 1 &&
        isdigit(static_cast<unsigned char>(s[1])) &&
        s.find('C') != string::npos) {

        size_t cPos = s.find('C');

        ll row = stoll(s.substr(1, cPos - 1));
        ll col = stoll(s.substr(cPos + 1));

        cout << columnToLetters(col) << row << '\n';
    } else {
        // Parse A1 format.
        size_t i = 0;

        while (i < s.size() &&
               isalpha(static_cast<unsigned char>(s[i]))) {
            i++;
        }

        string letters = s.substr(0, i);
        ll row = stoll(s.substr(i));
        ll col = lettersToColumn(letters);

        cout << 'R' << row << 'C' << col << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}