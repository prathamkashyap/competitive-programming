#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int open = 0;
    int answer = 0;

    for (char c : s) {
        if (c == '(') {
            open++;
        } else if (open > 0) {
            open--;
            answer += 2;
        }
    }

    cout << answer << '\n';

    return 0;
}