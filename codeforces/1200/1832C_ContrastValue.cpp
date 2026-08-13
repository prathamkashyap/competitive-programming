#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (long long &x : a)
            cin >> x;

        int answer = 1;

        int previousDirection = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1])
                continue;

            int currentDirection = (a[i] > a[i - 1]) ? 1 : -1;

            if (previousDirection == 0) {
                previousDirection = currentDirection;
                answer++;
            }
            else if (currentDirection != previousDirection) {
                previousDirection = currentDirection;
                answer++;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}