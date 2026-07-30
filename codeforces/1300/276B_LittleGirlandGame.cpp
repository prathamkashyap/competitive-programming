#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);

    for (char c : s) {
        freq[c - 'a']++;
    }

    int odd = 0;

    for (int x : freq) {
        if (x % 2 == 1) {
            odd++;
        }
    }

    if (odd <= 1 || odd % 2 == 1)
        cout << "First\n";
    else
        cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}