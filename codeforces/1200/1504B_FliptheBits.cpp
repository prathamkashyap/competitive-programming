#include <iostream>
#include <string>
using namespace std;

int solve() {
    int N;
    cin >> N;

    string S, T;
    cin >> S >> T;

    int zero = 0;
    int one = 0;

    for (char c : S) {
        if (c == '0') {
            zero++;
        } else {
            one++;
        }
    }

    bool flipped = false;

    for (int i = N - 1; i >= 0; i--) {
        char current = S[i];

        if (flipped) {
            current = (current == '0' ? '1' : '0');
        }

        if (current != T[i]) {
            // Prefix [0...i] must have equal 0s and 1s.
            if (zero != one) {
                return 0;
            }

            flipped = !flipped;
        }

        // Remove S[i] so that next iteration represents [0...i-1].
        if (S[i] == '0') {
            zero--;
        } else {
            one--;
        }
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}