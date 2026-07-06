#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>>T;
    while(T--){
        int n, k;
        string s;
        cin>>n>>k>>s;
        int z = 0, o = 0;
        for(char c: s){
            if(c=='0') z++;
            else o++;
        }
        int d = abs(z - o);
        int k_min = d / 2;
        int k_max = n / 2;
        if(k_min <= k && k <= k_max && ((k - k_min) % 2 == 0))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}