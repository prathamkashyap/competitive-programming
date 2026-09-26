#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> a(N);
    vector<long long> freq(N + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;

        --l;
        --r;

        freq[l]++;
        freq[r + 1]--;
    }

    // Convert difference array into actual frequencies.
    for (int i = 1; i < N; i++) {
        freq[i] += freq[i - 1];
    }

    sort(a.begin(), a.end());
    sort(freq.begin(), freq.begin() + N);

    long long answer = 0;

    for (int i = 0; i < N; i++) {
        answer += a[i] * freq[i];
    }

    cout << answer << '\n';

    return 0;
}