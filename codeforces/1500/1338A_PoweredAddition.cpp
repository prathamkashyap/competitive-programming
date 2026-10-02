#include <iostream>
#include <vector>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long maximum = a[0];
    int answer = 0;

    for (int i = 1; i < N; i++) {
        if (a[i] < maximum) {
            long long diff = maximum - a[i];

            int power = 0;
            long long added = 0;

            while (added < diff) {
                added = 2 * added + 1;
                power++;
            }

            answer = max(answer, power);
        } else {
            maximum = a[i];
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