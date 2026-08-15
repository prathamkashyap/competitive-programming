#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> laptops(n);

    for (auto &[price, quality] : laptops)
        cin >> price >> quality;

    sort(laptops.begin(), laptops.end());

    int maxQuality = 0;

    for (auto &[price, quality] : laptops) {
        if (quality < maxQuality) {
            cout << "Happy Alex\n";
            return 0;
        }

        maxQuality = max(maxQuality, quality);
    }

    cout << "Poor Alex\n";

    return 0;
}