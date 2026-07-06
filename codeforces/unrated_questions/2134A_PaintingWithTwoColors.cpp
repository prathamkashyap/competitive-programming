#include <iostream>

// Function to solve a single test case
void solve() {
    long long n, a, b;
    std::cin >> n >> a >> b;

    // Check if the parity of b and n are the same. This is a necessary condition.
    if (b % 2 != n % 2) {
        std::cout << "NO\n";
        return;
    }

    // If b and n have the same parity, we check the red segment.
    // We can succeed if either a also has the same parity as n,
    // or if a is small enough to be hidden inside b (a <= b).
    if ( (a % 2 == n % 2) || (a <= b) ) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
