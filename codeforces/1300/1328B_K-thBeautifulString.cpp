#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long x = 1;

        while (x * (x + 1) / 2 < k) {
            x++;
        }

        long long previous = x * (x - 1) / 2;
        long long position = k - previous;

        string s(n, 'a');

        s[n - x - 1] = 'b';
        s[n - position] = 'b';

        cout << s << '\n';
    }

    return 0;
}