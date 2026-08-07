#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int check(const string &s, char ch) {
    int left = 0;
    int right = s.size() - 1;
    int removed = 0;

    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        }
        else if (s[left] == ch) {
            left++;
            removed++;
        }
        else if (s[right] == ch) {
            right--;
            removed++;
        }
        else {
            return INF;
        }
    }

    return removed;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int answer = INF;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        answer = min(answer, check(s, ch));
    }

    if (answer == INF)
        cout << -1 << '\n';
    else
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