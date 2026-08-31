#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x, y;

        cin >> n >> x >> y;

        map<pair<long long, long long>, long long> freq;

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;

            long long remX = a % x;
            long long remY = a % y;

            long long needX = (x - remX) % x;

            answer += freq[{needX, remY}];

            freq[{remX, remY}]++;
        }

        cout << answer << '\n';
    }

    return 0;
}