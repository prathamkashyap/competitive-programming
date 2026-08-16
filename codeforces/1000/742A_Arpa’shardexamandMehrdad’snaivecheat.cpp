#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 1;
    } else {
        int ans[] = {6, 8, 4, 2};
        cout << ans[n % 4];
    }

    return 0;
}