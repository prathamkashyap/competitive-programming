#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // last[x] = last index where value x appears
        vector<int> last(1001, -1);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            last[x] = i + 1;
        }

        int answer = -1;

        for (int x = 1; x <= 1000; x++) {
            if (last[x] == -1)
                continue;

            for (int y = 1; y <= 1000; y++) {
                if (last[y] == -1)
                    continue;

                if (gcd(x, y) == 1) {
                    answer = max(answer, last[x] + last[y]);
                }
            }
        }

        cout << answer << '\n';
    }

    return 0;
}