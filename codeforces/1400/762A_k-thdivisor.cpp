#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K;
    cin >> N >> K;

    vector<long long> small, large;

    for (long long i = 1; i <= N / i; i++) {
        if (N % i == 0) {
            small.push_back(i);

            if (i != N / i) {
                large.push_back(N / i);
            }
        }
    }

    long long total = small.size() + large.size();

    if (K > total) {
        cout << -1 << '\n';
    } else if (K <= (long long)small.size()) {
        cout << small[K - 1] << '\n';
    } else {
        long long index = K - small.size();
        cout << large[large.size() - index] << '\n';
    }

    return 0;
}