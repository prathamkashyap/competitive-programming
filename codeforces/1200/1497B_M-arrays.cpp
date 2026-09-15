#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve() {
    int N, M;
    cin >> N >> M;

    vector<int> count(M, 0);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        count[x % M]++;
    }

    int answer = 0;

    if (count[0] > 0) {
        answer++;
    }

    for (int r = 1; r < M - r; r++) {
        int x = count[r];
        int y = count[M - r];

        if (x == 0 && y == 0) {
            continue;
        }

        answer += 1 + max(0, abs(x - y) - 1);
    }

    if (M % 2 == 0 && count[M / 2] > 0) {
        answer++;
    }

    return answer;
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