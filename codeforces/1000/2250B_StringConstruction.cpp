#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int blocks = n - k;

    if (blocks == 1) {
        cout << -1 << '\n';
        return;
    }

    int zeroCnt = (n + 1) / 2;
    int oneCnt = n / 2;

    int zeroBlocks = (blocks + 1) / 2;
    int oneBlocks = blocks / 2;

    if (zeroBlocks > zeroCnt || oneBlocks > oneCnt) {
        cout << -1 << '\n';
        return;
    }

    vector<int> len(blocks, 1);

    zeroCnt -= zeroBlocks;
    oneCnt -= oneBlocks;

    // Last 0-block
    len[(zeroBlocks - 1) * 2] += zeroCnt;

    // Last 1-block
    if (oneBlocks > 0)
        len[(oneBlocks - 1) * 2 + 1] += oneCnt;

    string ans;

    for (int i = 0; i < blocks; i++) {
        char ch = (i % 2 == 0 ? '0' : '1');
        ans.append(len[i], ch);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}