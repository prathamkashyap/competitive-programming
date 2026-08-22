#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int ans = 0;

        // a vs c, b vs d
        if ((a > c && b >= d) || (a >= c && b > d)) {
            ans += 2;
        }

        // a vs d, b vs c
        if ((a > d && b >= c) || (a >= d && b > c)) {
            ans += 2;
        }

        cout << ans << '\n';
    }

    return 0;
}