#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> dp(N + 1, 1);

    for (int length = 2; length <= K; length++) {
        vector<long long> next(N + 1, 0);

        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j += i) {
                next[j] += dp[i];
                next[j] %= MOD;
            }
        }

        dp = next;
    }

    long long answer = 0;

    for (int i = 1; i <= N; i++) {
        answer += dp[i];
        answer %= MOD;
    }

    cout << answer << '\n';

    return 0;
}