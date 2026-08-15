#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int answer = k;
        int evenCount = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            int needed = (k - x % k) % k;
            answer = min(answer, needed);

            if (x % 2 == 0)
                evenCount++;
        }

        if (k == 4) {
            int makeTwoEven = max(0, 2 - evenCount);
            answer = min(answer, makeTwoEven);
        }

        cout << answer << '\n';
    }

    return 0;
}