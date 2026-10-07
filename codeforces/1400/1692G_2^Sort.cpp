#include <iostream>
#include <vector>
using namespace std;

long long solve() {
    int N, K;
    cin >> N >> K;

    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long answer = 0;
    int run = 0;

    for (int i = 0; i < N - 1; i++) {
        if (a[i] < 2LL * a[i + 1]) {
            run++;

            if (run >= K) {
                answer++;
            }
        } else {
            run = 0;
        }
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