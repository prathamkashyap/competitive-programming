#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;

    set<int> distinct;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        distinct.insert(x);
    }

    if ((int)distinct.size() > K) {
        cout << -1 << '\n';
        return;
    }

    vector<int> pattern(distinct.begin(), distinct.end());

    while ((int)pattern.size() < K) {
        pattern.push_back(1);
    }

    cout << N * K << '\n';

    for (int i = 0; i < N; i++) {
        for (int x : pattern) {
            cout << x << ' ';
        }
    }

    cout << '\n';
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