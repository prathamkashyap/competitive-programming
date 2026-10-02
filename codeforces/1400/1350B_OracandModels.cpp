#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> a(N + 1);
    vector<int> dp(N + 1, 1);

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int answer = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            if (a[j] > a[i]) {
                dp[j] = max(dp[j], dp[i] + 1);
                answer = max(answer, dp[j]);
            }
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