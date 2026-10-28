#include <iostream>
#include <vector>
#include <climits>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAXA = 200000;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> spf(MAXA + 1, 0);

    for (int i = 2; i <= MAXA; i++) {
        if (spf[i] == 0) {
            spf[i] = i;

            if (1LL * i * i <= MAXA) {
                for (int j = i * i; j <= MAXA; j += i) {
                    if (spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    vector<int> cnt(MAXA + 1, 0);
    vector<int> mn1(MAXA + 1, INT_MAX);
    vector<int> mn2(MAXA + 1, INT_MAX);

    for (int x : a) {
        while (x > 1) {
            int p = spf[x];
            int exponent = 0;

            while (x % p == 0) {
                x /= p;
                exponent++;
            }

            cnt[p]++;

            if (exponent < mn1[p]) {
                mn2[p] = mn1[p];
                mn1[p] = exponent;
            } else if (exponent < mn2[p]) {
                mn2[p] = exponent;
            }
        }
    }

    ll ans = 1;

    for (int p = 2; p <= MAXA; p++) {
        int missing = n - cnt[p];
        int exponent = 0;

        if (missing == 1) {
            exponent = mn1[p];
        } else if (missing == 0) {
            exponent = mn2[p];
        }

        while (exponent--) {
            ans *= p;
        }
    }

    cout << ans << '\n';

    return 0;
}