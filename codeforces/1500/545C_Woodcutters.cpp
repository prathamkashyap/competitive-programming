#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> x(N);
    vector<long long> h(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> h[i];
    }

    if (N == 1) {
        cout << 1 << '\n';
        return 0;
    }

    int answer = 2;

    // First tree falls to the left.
    long long last = x[0];

    for (int i = 1; i < N - 1; i++) {

        // Try falling left.
        if (x[i] - h[i] > last) {
            answer++;
            last = x[i];
        }
        // Otherwise try falling right.
        else if (x[i] + h[i] < x[i + 1]) {
            answer++;
            last = x[i] + h[i];
        }
        // Otherwise leave it standing.
        else {
            last = x[i];
        }
    }

    // Last tree falls to the right.
    cout << answer << '\n';

    return 0;
}