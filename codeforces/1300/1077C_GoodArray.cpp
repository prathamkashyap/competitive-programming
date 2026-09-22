#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> a(N);

    long long sum = 0;
    long long mx = -1;
    long long secondMx = -1;
    int countMx = 0;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];

        if (a[i] > mx) {
            secondMx = mx;
            mx = a[i];
            countMx = 1;
        } else if (a[i] == mx) {
            countMx++;
        } else {
            secondMx = max(secondMx, a[i]);
        }
    }

    vector<int> answer;

    for (int i = 0; i < N; i++) {
        long long remainingMax;

        if (a[i] == mx && countMx == 1) {
            remainingMax = secondMx;
        } else {
            remainingMax = mx;
        }

        if (sum - a[i] == 2 * remainingMax) {
            answer.push_back(i + 1);
        }
    }

    cout << answer.size() << '\n';

    for (int index : answer) {
        cout << index << ' ';
    }

    cout << '\n';

    return 0;
}