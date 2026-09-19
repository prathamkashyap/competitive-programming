#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int left = (N - 1) / 2;
    int right = left + 1;

    while (left >= 0 || right < N) {
        if (left >= 0) {
            cout << a[left] << ' ';
            left--;
        }

        if (right < N) {
            cout << a[right] << ' ';
            right++;
        }
    }

    cout << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}