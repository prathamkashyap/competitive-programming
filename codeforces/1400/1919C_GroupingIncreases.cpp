#include <iostream>
#include <algorithm>
using namespace std;

int solve() {
    int N;
    cin >> N;

    int x = 1000000000;
    int y = 1000000000;

    int answer = 0;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (x > y) {
            swap(x, y);
        }

        if (a <= x) {
            x = a;
        }
        else if (a <= y) {
            y = a;
        }
        else {
            answer++;
            x = a;
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