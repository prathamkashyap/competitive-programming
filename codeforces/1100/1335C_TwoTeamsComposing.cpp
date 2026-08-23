#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }

        int mx = 0;
        int distinct = 0;

        for (int i = 1; i <= n; i++) {
            if (freq[i] > 0) {
                distinct++;
                mx = max(mx, freq[i]);
            }
        }

        int answer = max(
            min(mx - 1, distinct),
            min(mx, distinct - 1)
        );

        cout << answer << '\n';
    }

    return 0;
}