#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<long long> difference(n);

        for (int i = 0; i < n; i++) {
            difference[i] = a[i] - b[i];
        }

        long long maximum = difference[0];

        for (int i = 1; i < n; i++) {
            maximum = max(maximum, difference[i]);
        }

        vector<int> answer;

        for (int i = 0; i < n; i++) {
            if (difference[i] == maximum) {
                answer.push_back(i + 1);
            }
        }

        cout << answer.size() << '\n';

        for (int index : answer) {
            cout << index << ' ';
        }

        cout << '\n';
    }

    return 0;
}