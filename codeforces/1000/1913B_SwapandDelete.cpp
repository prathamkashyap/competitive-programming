#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int zeros = 0;
        int ones = 0;

        for (char c : s) {
            if (c == '0')
                zeros++;
            else
                ones++;
        }

        int answer = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                if (ones == 0) {
                    answer = s.size() - i;
                    break;
                }
                ones--;
            }
            else {
                if (zeros == 0) {
                    answer = s.size() - i;
                    break;
                }
                zeros--;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}