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
        int N, M;
        cin >> N >> M;

        int totalDigits = 0;
        vector<int> trailingZeros(N);

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;

            totalDigits += s.size();

            int zeros = 0;

            for (int j = (int)s.size() - 1; j >= 0 && s[j] == '0'; j--) {
                zeros++;
            }

            trailingZeros[i] = zeros;
        }

        sort(trailingZeros.rbegin(), trailingZeros.rend());

        for (int i = 0; i < N; i += 2) {
            totalDigits -= trailingZeros[i];
        }

        if (totalDigits > M) {
            cout << "Sasha\n";
        } else {
            cout << "Anna\n";
        }
    }

    return 0;
}