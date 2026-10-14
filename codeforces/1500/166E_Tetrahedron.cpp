#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long atD = 1;
    long long atOther = 0;

    for (int i = 1; i <= N; i++) {
        long long newAtD = 3 * atOther % MOD;
        long long newAtOther = (atD + 2 * atOther) % MOD;

        atD = newAtD;
        atOther = newAtOther;
    }

    cout << atD << '\n';

    return 0;
}