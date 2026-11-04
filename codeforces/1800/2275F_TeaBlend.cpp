#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1000000;

vector<int> spf(MAXA + 1);

void sieve() {
    iota(spf.begin(), spf.end(), 0);

    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> factors(n);
    unordered_map<int, int> freq;

    freq.reserve(n * 2);
    freq.max_load_factor(0.7);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int kernel = 1;

        while (x > 1) {
            int p = spf[x];
            int parity = 0;

            while (x % p == 0) {
                x /= p;
                parity ^= 1;
            }

            if (parity) {
                factors[i].push_back(p);
                kernel *= p;
            }
        }

        freq[kernel]++;
    }

    set<int> oddPrimes;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        for (int p : factors[i]) {
            auto it = oddPrimes.find(p);

            if (it == oddPrimes.end()) {
                oddPrimes.insert(p);
            } else {
                oddPrimes.erase(it);
            }
        }

        if (oddPrimes.size() > 7) {
            continue;
        }

        long long kernel = 1;

        for (int p : oddPrimes) {
            kernel *= p;

            if (kernel > MAXA) {
                break;
            }
        }

        if (kernel <= MAXA) {
            auto it = freq.find((int)kernel);

            if (it != freq.end()) {
                ans += it->second;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}