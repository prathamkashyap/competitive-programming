#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    int ones = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ones += a[i];
    }

    int currentGain = 0;
    int maxGain = -1000000000;

    for (int x : a) {
        int gain = (x == 0 ? 1 : -1);

        currentGain = max(gain, currentGain + gain);
        maxGain = max(maxGain, currentGain);
    }

    cout << ones + maxGain << '\n';

    return 0;
}