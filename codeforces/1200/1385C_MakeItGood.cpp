#include <iostream>
#include <vector>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int i = N - 1;

    while (i > 0 && a[i - 1] >= a[i]) {
        i--;
    }

    while (i > 0 && a[i - 1] <= a[i]) {
        i--;
    }

    return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << '\n';
    }

    return 0;
}