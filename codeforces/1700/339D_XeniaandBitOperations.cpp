#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    int sz = 1 << n;
    vector<int> tree(2 * sz);

    for (int i = 0; i < sz; i++) {
        cin >> tree[sz + i];
    }

    // Build the tree, starting from the level above the leaves.
    bool useOr = true;

    for (int width = sz; width > 1; width /= 2) {
        for (int i = width / 2; i < width; i++) {
            if (useOr) {
                tree[i] = tree[2 * i] | tree[2 * i + 1];
            } else {
                tree[i] = tree[2 * i] ^ tree[2 * i + 1];
            }
        }

        useOr = !useOr;
    }

    while (m--) {
        int p, b;
        cin >> p >> b;

        // Update the leaf (input positions are 1-indexed).
        int pos = sz + p - 1;
        tree[pos] = b;

        // Recalculate ancestors, alternating OR and XOR.
        useOr = true;

        while (pos > 1) {
            pos /= 2;

            if (useOr) {
                tree[pos] = tree[2 * pos] | tree[2 * pos + 1];
            } else {
                tree[pos] = tree[2 * pos] ^ tree[2 * pos + 1];
            }

            useOr = !useOr;
        }

        cout << tree[1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}