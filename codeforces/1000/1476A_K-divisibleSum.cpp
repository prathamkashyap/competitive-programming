#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long sum = ((n + k - 1) / k) * k;

        long long answer = (sum + n - 1) / n;

        cout << answer << '\n';
    }

    return 0;
}