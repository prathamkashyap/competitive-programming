#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string s;
        cin >> s;

        vector<long long> positions;

        for (int i = 0; i < N; i++) {
            if (s[i] == '*') {
                positions.push_back(i);
            }
        }

        int sheep = positions.size();

        if (sheep == 0 || sheep == 1) {
            cout << 0 << '\n';
            continue;
        }

        vector<long long> b(sheep);

        for (int i = 0; i < sheep; i++) {
            b[i] = positions[i] - i;
        }

        long long median = b[sheep / 2];
        long long answer = 0;

        for (long long x : b) {
            answer += llabs(x - median);
        }

        cout << answer << '\n';
    }

    return 0;
}