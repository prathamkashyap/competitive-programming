#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> cnt(4,0);
    for(int i=0;i<n;i++){
        int x; cin >> x;
        cnt[x]++;
    }
    int keep = max({cnt[1], cnt[2], cnt[3]});
    cout << n - keep << "\n";
    return 0;
}
