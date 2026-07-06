#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    long long total = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        total += a[i];
    }
    int ans = 0;
    for(int x : a){
        if((total - x) % 2 == 0) ans++;
    }
    cout << ans << "\n";
    return 0;
}
