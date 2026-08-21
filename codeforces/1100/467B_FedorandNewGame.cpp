#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> armies(m);

    for (int i = 0; i < m; i++) {
        cin >> armies[i];
    }

    int fedor;
    cin >> fedor;

    int players = 0;

    for (int x : armies) {
        int diff = x ^ fedor;
        int count = 0;

        while (diff > 0) {
            count += diff & 1;
            diff >>= 1;
        }

        if (count <= k) {
            players++;
        }
    }

    cout << players << '\n';

    return 0;
}