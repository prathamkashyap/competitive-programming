#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;

        int x = 0, y = 0;
        bool found = false;
        for (int rep = 0; rep < 100; ++rep) {  // 100 cycles is enough for constraints
            for (char move : s) {
                if (move == 'N') y += 1;
                if (move == 'S') y -= 1;
                if (move == 'E') x += 1;
                if (move == 'W') x -= 1;

                if (x == a && y == b) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        cout << (found ? "YES" : "NO") << "\n";
    }
    return 0;
}
