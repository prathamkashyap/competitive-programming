#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> deck(n);

    for (int i = 0; i < n; i++) {
        cin >> deck[i];
    }

    while (q--) {
        int x;
        cin >> x;

        // Find the first occurrence of x
        int pos = 0;

        while (deck[pos] != x) {
            pos++;
        }

        // Output its current 1-based position
        cout << pos + 1 << " ";

        // Move the card to the front
        for (int i = pos; i >= 1; i--) {
            deck[i] = deck[i - 1];
        }

        deck[0] = x;
    }

    cout << '\n';

    return 0;
}