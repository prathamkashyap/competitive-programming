#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int N, X, Y, Z;
    cin >> N >> X >> Y >> Z;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int answer = 0;

    for (int mask = 0; mask < (1 << N); mask++) {
        int count = 0;
        int sum = 0;
        int minimum = 1000000000;
        int maximum = -1000000000;

        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                count++;
                sum += a[i];
                minimum = min(minimum, a[i]);
                maximum = max(maximum, a[i]);
            }
        }

        if (count >= 2 &&
            sum >= X &&
            sum <= Y &&
            maximum - minimum >= Z) {
            answer++;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << '\n';

    return 0;
}