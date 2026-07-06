#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long current = 1;
    long long totalTime = 0;

    for (long long i = 0; i < m; i++) {
        long long house;
        cin >> house;

        if (house >= current) {
            totalTime += house - current;
        } else {
            totalTime += (n - current) + house;
        }

        current = house;
    }

    cout << totalTime << '\n';

    return 0;
}