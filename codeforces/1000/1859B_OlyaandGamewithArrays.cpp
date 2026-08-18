#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long sum = 0;
        int globalMin = INT_MAX;
        int smallestSecond = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;

            vector<int> a(m);

            for (int j = 0; j < m; ++j)
                cin >> a[j];

            sort(a.begin(), a.end());

            globalMin = min(globalMin, a[0]);
            smallestSecond = min(smallestSecond, a[1]);
            sum += a[1];
        }

        cout << sum - smallestSecond + globalMin << '\n';
    }

    return 0;
}