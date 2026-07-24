#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int neg = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == -1)
                neg++;
        }

        if (n % 2 == 0 && (neg % 2 == (n / 2) % 2))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}