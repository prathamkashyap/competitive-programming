#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int left = 0;
        int right = n - 1;

        int aliceLast = 0;
        int bobLast = 0;

        int aliceTotal = 0;
        int bobTotal = 0;

        int moves = 0;

        while (left <= right) {
            int aliceCurrent = 0;

            while (left <= right && aliceCurrent <= bobLast) {
                aliceCurrent += a[left];
                left++;
            }

            aliceLast = aliceCurrent;
            aliceTotal += aliceCurrent;
            moves++;

            if (left > right) {
                break;
            }

            int bobCurrent = 0;

            while (left <= right && bobCurrent <= aliceLast) {
                bobCurrent += a[right];
                right--;
            }

            bobLast = bobCurrent;
            bobTotal += bobCurrent;
            moves++;
        }

        cout << moves << " " << aliceTotal << " " << bobTotal << '\n';
    }

    return 0;
}