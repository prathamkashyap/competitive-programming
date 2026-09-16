#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y, n;
    cin >> x >> y >> n;

    x %= MOD;
    y %= MOD;

    long long answer;

    switch (n % 6) {
        case 1:
            answer = x;
            break;
        case 2:
            answer = y;
            break;
        case 3:
            answer = y - x;
            break;
        case 4:
            answer = -x;
            break;
        case 5:
            answer = -y;
            break;
        default:
            answer = x - y;
            break;
    }

    answer = (answer % MOD + MOD) % MOD;

    cout << answer << '\n';

    return 0;
}