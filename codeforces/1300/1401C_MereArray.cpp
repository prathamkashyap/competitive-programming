#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long mn = *min_element(a.begin(), a.end());

    vector<long long> sorted = a;
    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < N; i++) {
        if (a[i] != sorted[i] && a[i] % mn != 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}