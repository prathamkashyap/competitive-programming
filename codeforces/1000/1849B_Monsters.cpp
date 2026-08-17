#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> monsters;

        for (int i = 1; i <= n; ++i) {
            int health;
            cin >> health;

            int remainder = health % k;

            if (remainder == 0)
                remainder = k;

            monsters.push_back({remainder, i});
        }

        sort(monsters.begin(), monsters.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first != b.first)
                     return a.first > b.first;

                 return a.second < b.second;
             });

        for (const auto& monster : monsters)
            cout << monster.second << ' ';

        cout << '\n';
    }

    return 0;
}