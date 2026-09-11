#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;

        cin >> n >> s;

        int answer = n - 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i - 1] == s[i + 1]) {
                answer--;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}