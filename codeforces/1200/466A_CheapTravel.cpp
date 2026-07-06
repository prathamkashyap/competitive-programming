#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    
    // If special tickets don't provide discount
    if (m * a <= b) {
        cout << n * a << endl;
    }
    // Special tickets are beneficial
    else {
        int fullTickets = (n / m) * b;
        int remainder = min((n % m) * a, b);
        cout << fullTickets + remainder << endl;
    }
    
    return 0;
}
