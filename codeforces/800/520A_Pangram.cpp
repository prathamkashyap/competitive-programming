#include <iostream>
#include <set>
#include <cctype>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    set<char> letters;

    for (char ch : s) {
        letters.insert(tolower(ch));
    }

    if (letters.size() == 26)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}