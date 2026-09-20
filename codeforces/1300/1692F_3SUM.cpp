#include <iostream>
#include <vector>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> a[10];

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        int digit = x % 10;

        if (a[digit].size() < 3) {
            a[digit].push_back(x);
        }
    }

    vector<int> values;

    for (int i = 0; i < 10; i++) {
        for (int x : a[i]) {
            values.push_back(x);
        }
    }

    for (int i = 0; i < (int)values.size(); i++) {
        for (int j = i + 1; j < (int)values.size(); j++) {
            for (int k = j + 1; k < (int)values.size(); k++) {
                if ((1LL * values[i] + values[j] + values[k]) % 10 == 3) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        if (solve()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}