#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<bool> processed(n + 1, false);
        long long answer = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                continue;
            }

            for (int j = i; j <= n; j += i) {
                if (s[j - 1] == '1') {
                    break;
                }

                if (!processed[j]) {
                    answer += i;
                    processed[j] = true;
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}