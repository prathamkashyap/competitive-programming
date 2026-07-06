#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int t; cin >> t;
    cin.ignore();  // consume newline after t
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string word;
        string result;
        while (ss >> word) {
            result += word[0];  // append first letter of each word
        }
        cout << result << "\n";
    }
    return 0;
}
