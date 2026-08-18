#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;

        long long common = min(x, y);

        long long answer = common * min(b, 2 * a)
                          + (max(x, y) - common) * a;

        cout << answer << '\n';
    }

    return 0;
}