#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        set<char> seen;
        long long answer = 0;

        for (char c : s) {
            seen.insert(c);
            answer += seen.size();
        }

        cout << answer << '\n';
    }

    return 0;
}