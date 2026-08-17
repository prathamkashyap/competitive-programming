#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        long long ans = 0;
        int len = 0;

        for (int i = 0; i < n; i++) {
            int temperature;
            cin >> temperature;

            if (temperature <= q) {
                len++;

                if (len >= k)
                    ans += len - k + 1;
            } else {
                len = 0;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}