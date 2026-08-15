#include <iostream>
#include <vector>
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

        vector<int> a(n);

        for (int &x : a)
            cin >> x;

        int left = 0;
        int right = n - 1;
        int minimum = 1;
        int maximum = n;

        while (left < right) {
            if (a[left] == minimum) {
                left++;
                minimum++;
            }
            else if (a[left] == maximum) {
                left++;
                maximum--;
            }
            else if (a[right] == minimum) {
                right--;
                minimum++;
            }
            else if (a[right] == maximum) {
                right--;
                maximum--;
            }
            else {
                cout << left + 1 << " " << right + 1 << '\n';
                break;
            }
        }

        if (left >= right)
            cout << -1 << '\n';
    }

    return 0;
}