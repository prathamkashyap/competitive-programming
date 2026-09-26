#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    size_t ab = s.find("AB");

    if (ab != string::npos) {
        size_t ba = s.find("BA", ab + 2);

        if (ba != string::npos) {
            cout << "YES\n";
            return 0;
        }
    }

    size_t ba = s.find("BA");

    if (ba != string::npos) {
        size_t ab = s.find("AB", ba + 2);

        if (ab != string::npos) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}