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

        vector<long long> a(n);
        string s;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cin >> s;

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
        }

        int left = 0;
        int right = n - 1;
        long long answer = 0;

        while (left < right) {
            while (left < right && s[left] != 'L') {
                left++;
            }

            while (left < right && s[right] != 'R') {
                right--;
            }

            if (left < right) {
                answer += prefix[right + 1] - prefix[left];
                left++;
                right--;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}