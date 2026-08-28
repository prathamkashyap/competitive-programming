#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    int twentyFive = 0;
    int fifty = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] == 25) {
            twentyFive++;
        }
        else if (a[i] == 50) {
            if (twentyFive == 0) {
                cout << "NO\n";
                return 0;
            }

            twentyFive--;
            fifty++;
        }
        else {
            // Customer pays 100.
            // Prefer 50 + 25.
            if (fifty > 0 && twentyFive > 0) {
                fifty--;
                twentyFive--;
            }
            else if (twentyFive >= 3) {
                twentyFive -= 3;
            }
            else {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}