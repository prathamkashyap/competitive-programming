#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> prefZero(n + 1, 0);
    vector<int> prefOne(n + 1, 0);

    vector<int> ones, zeros;

    ll inversions = 0;
    ll oneCount = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        prefZero[i + 1] = prefZero[i] + (a[i] == 0);
        prefOne[i + 1] = prefOne[i] + (a[i] == 1);

        if (a[i] == 1) {
            ones.push_back(i);
            oneCount++;
        } else {
            zeros.push_back(i);
            inversions += oneCount;
        }
    }

    string s;
    cin >> s;

    int totalOnes = ones.size();
    int totalZeros = zeros.size();

    int removedOnes = 0;
    int removedZeros = 0;

    cout << inversions;

    for (char c : s) {
        if (c == '1') {
            if (removedOnes < totalOnes) {
                int pos = ones[removedOnes];

                ll remainingZeros = totalZeros - removedZeros;
                ll zerosBefore = prefZero[pos];

                ll reduction = max(0LL, remainingZeros - zerosBefore);

                inversions -= reduction;
                removedOnes++;
            }
        } else {
            if (removedZeros < totalZeros) {
                int pos = zeros[totalZeros - removedZeros - 1];

                ll onesBefore = prefOne[pos];
                ll reduction = max(0LL, onesBefore - removedOnes);

                inversions -= reduction;
                removedZeros++;
            }
        }

        cout << ' ' << inversions;
    }

    cout << '\n';
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