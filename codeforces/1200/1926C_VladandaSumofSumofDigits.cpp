#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXN = 200000;

    vector<int> digitSum(MAXN + 1, 0);
    vector<int> prefix(MAXN + 1, 0);

    for (int i = 1; i <= MAXN; i++) {
        digitSum[i] = digitSum[i / 10] + (i % 10);
        prefix[i] = prefix[i - 1] + digitSum[i];
    }

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        cout << prefix[n] << '\n';
    }

    return 0;
}