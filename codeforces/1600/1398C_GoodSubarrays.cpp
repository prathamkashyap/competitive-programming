#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    unordered_map<int, ll> freq;
    freq[0] = 1;

    int prefix = 0;
    ll ans = 0;

    for (char c : s) {
        prefix += (c - '0') - 1;

        ans += freq[prefix];
        freq[prefix]++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}