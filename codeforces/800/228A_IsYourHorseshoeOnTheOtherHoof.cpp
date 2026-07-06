#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> colors;
    int x;

    for (int i = 0; i < 4; i++) {
        cin >> x;
        colors.insert(x);
    }

    // Number of duplicates = 4 - unique colors
    cout << 4 - colors.size();

    return 0;
}