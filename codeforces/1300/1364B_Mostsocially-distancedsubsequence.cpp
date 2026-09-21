#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> a(N);

        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        vector<long long> b;

        for (int i = 0; i < N; i++) {
            if (b.empty() || b.back() != a[i]) {
                b.push_back(a[i]);
            }
        }

        vector<long long> ans;

        if (b.size() == 1) {
            ans.push_back(b[0]);
        } else {
            ans.push_back(b[0]);

            for (int i = 1; i + 1 < (int)b.size(); i++) {
                if ((b[i] > b[i - 1] && b[i] > b[i + 1]) ||
                    (b[i] < b[i - 1] && b[i] < b[i + 1])) {
                    ans.push_back(b[i]);
                }
            }

            ans.push_back(b.back());
        }

        cout << ans.size() << '\n';

        for (long long x : ans) {
            cout << x << ' ';
        }

        cout << '\n';
    }

    return 0;
}