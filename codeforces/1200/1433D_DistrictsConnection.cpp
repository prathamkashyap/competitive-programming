#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> roads;
        int bridge = -1;

        for (int i = 1; i < n; i++) {
            if (a[i] != a[0]) {
                roads.push_back({1, i + 1});
                bridge = i + 1;
            }
        }

        if (bridge == -1) {
            cout << "NO\n";
            continue;
        }

        for (int i = 1; i < n; i++) {
            if (a[i] == a[0]) {
                roads.push_back({bridge, i + 1});
            }
        }

        cout << "YES\n";

        for (auto [u, v] : roads) {
            cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}