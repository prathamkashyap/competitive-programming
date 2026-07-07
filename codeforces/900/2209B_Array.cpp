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

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = 0; i < n; i++) {
            int smaller = 0, greater = 0;

            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i])
                    smaller++;
                else if (a[j] > a[i])
                    greater++;
            }

            cout << max(smaller, greater) << " ";
        }

        cout << '\n';
    }

    return 0;
}