// #include <iostream>
// #include <algorithm>
// using namespace std;

// int main() {
//     int n, m, a, b;
//     cin >> n >> m >> a >> b;
    
//     // If special tickets don't provide discount
//     if (m * a <= b) {
//         cout << n * a << endl;
//     }
//     // Special tickets are beneficial
//     else {
//         int fullTickets = (n / m) * b;
//         int remainder = min((n % m) * a, b);
//         cout << fullTickets + remainder << endl;
//     }
    
//     return 0;
// }


#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int onlySingles = n * a;
    int onlySpecial = ((n + m - 1) / m) * b;
    int mixed = (n / m) * b + (n % m) * a;

    cout << min({onlySingles, onlySpecial, mixed}) << '\n';

    return 0;
}