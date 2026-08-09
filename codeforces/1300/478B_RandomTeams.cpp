#include <iostream>

using namespace std;

using ll = long long;

ll pairs(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    ll teamsOfLargerSize = n % m;
    ll smallerTeamSize = n / m;

    ll minimumPairs =
        teamsOfLargerSize * pairs(smallerTeamSize + 1) +
        (m - teamsOfLargerSize) * pairs(smallerTeamSize);

    ll largestTeamSize = n - m + 1;

    ll maximumPairs = pairs(largestTeamSize);

    cout << minimumPairs << ' ' << maximumPairs << '\n';

    return 0;
}