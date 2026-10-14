#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long r, x, y, x1, y1;
    cin >> r >> x >> y >> x1 >> y1;

    long long dx = x1 - x;
    long long dy = y1 - y;

    long double distance = sqrtl(
        (long double)dx * dx + (long double)dy * dy
    );

    long long answer = (long long)ceill(distance / (2.0L * r));

    cout << answer << '\n';

    return 0;
}