#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int answer = 0;

        int previous = -1;
        int previousCount = 0;

        int i = 0;

        while (i < n) {
            int current = a[i];
            int currentCount = 0;

            while (i < n && a[i] == current) {
                currentCount++;
                i++;
            }

            // If there is a gap, all current dolls
            // must start new groups.
            if (current != previous + 1) {
                answer += currentCount;
            }
            else {
                // Some current dolls can continue
                // the groups from the previous number.
                if (currentCount > previousCount) {
                    answer += currentCount - previousCount;
                }
            }

            previous = current;
            previousCount = currentCount;
        }

        cout << answer << '\n';
    }

    return 0;
}