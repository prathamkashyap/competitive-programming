#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(const vector<long long>& a, long long k, long long target) {
    int n = a.size();
    int median = n / 2;

    long long needed = 0;

    for (int i = median; i < n; i++) {
        if (a[i] < target) {
            needed += target - a[i];

            if (needed > k) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;

    cin >> N >> K;

    vector<long long> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long left = a[N / 2];
    long long right = a[N / 2] + K;
    long long answer = left;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (possible(a, K, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}