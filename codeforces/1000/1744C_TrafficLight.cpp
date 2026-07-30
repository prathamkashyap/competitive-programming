#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    char c;
    cin >> n >> c;

    string s;
    cin >> s;

    if (c == 'g') {
        cout << 0 << '\n';
        return;
    }

    s += s;

    int nextGreen = -1;
    int answer = 0;

    for (int i = 2 * n - 1; i >= 0; i--) {
        if (s[i] == 'g') {
            nextGreen = i;
        }

        if (i < n && s[i] == c) {
            answer = max(answer, nextGreen - i);
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}