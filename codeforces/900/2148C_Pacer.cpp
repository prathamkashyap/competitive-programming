#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        int n; ll m;
        cin >> n >> m;
        ll prev_a = 0;
        int prev_b = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll a; int b;
            cin >> a >> b;
            ll dt = a - prev_a;
            int db = abs(b - prev_b);
            if( (dt % 2) == (db % 2) ) ans += dt;
            else ans += dt - 1;
            prev_a = a;
            prev_b = b;
        }
        ans += (m - prev_a);
        cout << ans << "\n";
    }
    return 0;
}