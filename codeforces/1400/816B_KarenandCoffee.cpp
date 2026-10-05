#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, Q;
    cin >> N >> K >> Q;

    const int MAX_TEMP = 200000;

    vector<int> diff(MAX_TEMP + 2, 0);

    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;

        diff[l]++;
        diff[r + 1]--;
    }

    vector<int> prefix(MAX_TEMP + 1, 0);

    int covered = 0;

    for (int temperature = 1; temperature <= MAX_TEMP; temperature++) {
        covered += diff[temperature];

        prefix[temperature] = prefix[temperature - 1];

        if (covered >= K) {
            prefix[temperature]++;
        }
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;

        cout << prefix[r] - prefix[l - 1] << '\n';
    }

    return 0;
}