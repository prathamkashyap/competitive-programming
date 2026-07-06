#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    if (!(cin >> a >> b)) return 0;
    string ans; 
    ans.resize(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        ans[i] = (a[i] == b[i] ? '0' : '1');
    cout << ans << '\n';
    return 0;
}
