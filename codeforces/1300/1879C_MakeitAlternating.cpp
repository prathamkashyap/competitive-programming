#include <iostream>
#include <string>
using namespace std;

const long long MOD = 998244353;

int solve() {
    string s;
    cin >> s;

    int deletions = 0;
    long long ways = 1;

    for (int i = 0; i < (int)s.size(); ) {
        int j = i;

        while (j < (int)s.size() && s[j] == s[i]) {
            j++;
        }

        int len = j - i;

        deletions += len - 1;
        ways = ways * len % MOD;

        i = j;
    }

    for (int i = 1; i <= deletions; i++) {
        ways = ways * i % MOD;
    }

    cout << deletions << ' ' << ways << '\n';

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}