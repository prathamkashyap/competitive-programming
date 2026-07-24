#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    bool majorityEven = (even > odd);

    for (int i = 0; i < n; i++) {
        if (majorityEven && a[i] % 2 != 0) {
            cout << i + 1 << '\n';
            break;
        }
        if (!majorityEven && a[i] % 2 == 0) {
            cout << i + 1 << '\n';
            break;
        }
    }

    return 0;
}