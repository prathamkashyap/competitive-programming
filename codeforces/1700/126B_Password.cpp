#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = static_cast<int>(s.size());
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    int maxInside = 0;

    for (int i = 0; i < n - 1; i++) {
        maxInside = max(maxInside, pi[i]);
    }

    int len = pi[n - 1];

    while (len > maxInside) {
        len = pi[len - 1];
    }

    if (len == 0) {
        cout << "Just a legend\n";
    } else {
        cout << s.substr(0, len) << '\n';
    }

    return 0;
}