#include <iostream>
#include <map>
using namespace std;

long long solve() {
    int N;
    long long K;

    cin >> N >> K;

    map<long long, long long> count;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;

        long long remainder = x % K;

        if (remainder != 0) {
            count[remainder]++;
        }
    }

    long long answer = 0;

    for (auto [remainder, frequency] : count) {
        long long need = K - remainder;

        long long lastX = need + (frequency - 1) * K;

        answer = max(answer, lastX + 1);
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