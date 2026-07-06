#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isBeautiful(int year) {
    string s = to_string(year);
    set<char> digits;
    for (char c : s) {
        if (digits.count(c)) return false;
        digits.insert(c);
    }
    return true;
}

int main() {
    int y;
    cin >> y;
    
    int year = y + 1;
    while (!isBeautiful(year)) {
        year++;
    }
    
    cout << year << "\n";
    return 0;
}
