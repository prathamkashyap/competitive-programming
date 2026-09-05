#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<bool> allowed(26, false);

    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        allowed[c - 'a'] = true;
    }

    long long answer = 0;
    long long length = 0;

    for (char c : s) {
        if (allowed[c - 'a']) {
            length++;
        } else {
            answer += length * (length + 1) / 2;
            length = 0;
        }
    }

    answer += length * (length + 1) / 2;

    cout << answer << '\n';

    return 0;
}