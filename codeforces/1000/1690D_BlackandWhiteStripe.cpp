#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;

        cin >> n >> k;
        cin >> s;

        int white = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'W')
                white++;
        }

        int answer = white;

        // Slide the window
        for (int i = k; i < n; i++) {
            if (s[i - k] == 'W')
                white--;

            if (s[i] == 'W')
                white++;

            answer = min(answer, white);
        }

        cout << answer << '\n';
    }

    return 0;
}