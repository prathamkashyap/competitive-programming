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
        string s;
        cin >> s;

        int cnt[4] = {};
        int left = 0;
        int answer = s.size() + 1;

        for (int right = 0; right < s.size(); right++) {
            cnt[s[right] - '0']++;

            while (cnt[1] > 0 && cnt[2] > 0 && cnt[3] > 0) {
                answer = min(answer, right - left + 1);

                cnt[s[left] - '0']--;
                left++;
            }
        }

        cout << (answer == s.size() + 1 ? 0 : answer) << '\n';
    }

    return 0;
}