#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve() {
    int N;
    long long X;

    cin >> N >> X;

    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long prefix = 0;
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        prefix += a[i];

        if (prefix > X) {
            break;
        }

        long long count = (X - prefix) / (i + 1) + 1;
        answer += count;
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