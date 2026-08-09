#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    int total = n * (n - 1) / 2;

    vector<ll> minimums(total);

    for (int i = 0; i < total; i++)
        cin >> minimums[i];

    sort(minimums.begin(), minimums.end());

    vector<ll> answer;

    int index = 0;

    for (int remaining = n - 1; remaining >= 1; remaining--) {
        answer.push_back(minimums[index]);
        index += remaining;
    }

    answer.push_back(1000000000LL);

    for (ll x : answer)
        cout << x << ' ';

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}