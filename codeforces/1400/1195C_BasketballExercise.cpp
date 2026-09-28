#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> top(N);
    vector<long long> bottom(N);

    for (int i = 0; i < N; i++) {
        cin >> top[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> bottom[i];
    }

    long long none = 0;
    long long takeTop = top[0];
    long long takeBottom = bottom[0];

    for (int i = 1; i < N; i++) {
        long long newNone = max({none, takeTop, takeBottom});

        long long newTop = top[i] + max(none, takeBottom);

        long long newBottom = bottom[i] + max(none, takeTop);

        none = newNone;
        takeTop = newTop;
        takeBottom = newBottom;
    }

    cout << max({none, takeTop, takeBottom}) << '\n';

    return 0;
}