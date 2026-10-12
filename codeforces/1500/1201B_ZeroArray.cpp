#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long sum = 0;
    long long maximum = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;

        sum += x;
        maximum = max(maximum, x);
    }

    if (sum % 2 == 0 && maximum <= sum / 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}