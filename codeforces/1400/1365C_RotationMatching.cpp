#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    vector<int> pos(n + 1);
    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        int shift = (pos[b[i]] - i + n) % n;
        cnt[shift]++;
    }

    cout << *max_element(cnt.begin(), cnt.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}