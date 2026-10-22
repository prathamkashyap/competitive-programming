#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string recipe;
    cin >> recipe;

    ll stockB, stockS, stockC;
    cin >> stockB >> stockS >> stockC;

    ll priceB, priceS, priceC;
    cin >> priceB >> priceS >> priceC;

    ll r;
    cin >> r;

    ll cntB = 0, cntS = 0, cntC = 0;

    for (char c : recipe) {
        if (c == 'B') {
            cntB++;
        } else if (c == 'S') {
            cntS++;
        } else {
            cntC++;
        }
    }

    auto canMake = [&](ll x) -> bool {
        ll needB = max(0LL, x * cntB - stockB);
        ll needS = max(0LL, x * cntS - stockS);
        ll needC = max(0LL, x * cntC - stockC);

        ll cost = needB * priceB
                + needS * priceS
                + needC * priceC;

        return cost <= r;
    };

    ll low = 0, high = 10000000000000LL;

    while (low < high) {
        ll mid = low + (high - low + 1) / 2;

        if (canMake(mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }

    cout << low << '\n';

    return 0;
}