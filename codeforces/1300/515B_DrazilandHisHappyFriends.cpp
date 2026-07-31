#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int g = gcd(n, m);

    vector<bool> happyComponent(g, false);

    int b;
    cin >> b;

    while (b--) {
        int x;
        cin >> x;
        happyComponent[x % g] = true;
    }

    int girls;
    cin >> girls;

    while (girls--) {
        int x;
        cin >> x;
        happyComponent[x % g] = true;
    }

    for (bool happy : happyComponent) {
        if (!happy) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}