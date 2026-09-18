#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, Q;
        cin >> N >> Q;

        string S, Tstr;
        cin >> S >> Tstr;

        vector<vector<int>> prefS(N + 1, vector<int>(26, 0));
        vector<vector<int>> prefT(N + 1, vector<int>(26, 0));

        for (int i = 0; i < N; i++) {
            prefS[i + 1] = prefS[i];
            prefT[i + 1] = prefT[i];

            prefS[i + 1][S[i] - 'a']++;
            prefT[i + 1][Tstr[i] - 'a']++;
        }

        while (Q--) {
            int l, r;
            cin >> l >> r;

            int answer = 0;

            for (int c = 0; c < 26; c++) {
                int countS = prefS[r][c] - prefS[l - 1][c];
                int countT = prefT[r][c] - prefT[l - 1][c];

                if (countS > countT) {
                    answer += countS - countT;
                }
            }

            cout << answer << '\n';
        }
    }

    return 0;
}