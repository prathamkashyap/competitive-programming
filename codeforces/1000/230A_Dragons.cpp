#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int kiritoStrength, dragonCount;
    cin >> kiritoStrength >> dragonCount;

    vector<pair<int, int>> dragons;

    for (int i = 0; i < dragonCount; i++) {
        int dragonStrength, bonusStrength;
        cin >> dragonStrength >> bonusStrength;

        dragons.push_back({dragonStrength, bonusStrength});
    }

    sort(dragons.begin(), dragons.end());

    for (int i = 0; i < dragonCount; i++) {
        if (kiritoStrength <= dragons[i].first) {
            cout << "NO\n";
            return 0;
        }

        kiritoStrength += dragons[i].second;
    }

    cout << "YES\n";

    return 0;
}