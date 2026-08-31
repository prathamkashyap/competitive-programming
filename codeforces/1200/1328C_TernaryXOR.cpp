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

        string a(n, '0');
        string b(n, '0');

        bool foundOne = false;

        for (int i = 0; i < n; i++) {
            if (foundOne) {
                a[i] = '0';
                b[i] = s[i];
            }
            else if (s[i] == '0') {
                a[i] = '0';
                b[i] = '0';
            }
            else if (s[i] == '2') {
                a[i] = '1';
                b[i] = '1';
            }
            else {
                a[i] = '1';
                b[i] = '0';
                foundOne = true;
            }
        }

        cout << a << '\n';
        cout << b << '\n';
    }

    return 0;
}