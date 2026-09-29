#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> c(N);

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        c[i] = x;
    }

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        c[i] -= x;
    }

    sort(c.begin(), c.end());

    long long answer = 0;
    int left = 0;
    int right = N - 1;

    while (left < right) {
        if (c[left] + c[right] > 0) {
            // c[left] pairs with every element from left+1 to right.
            answer += right - left;
            right--;
        } else {
            left++;
        }
    }

    cout << answer << '\n';

    return 0;
}