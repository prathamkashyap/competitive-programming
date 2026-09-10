#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> t(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    long long currentTime = 0;
    int satisfied = 0;

    for (long long time : t) {
        if (currentTime <= time) {
            satisfied++;
            currentTime += time;
        }
    }

    cout << satisfied << '\n';

    return 0;
}