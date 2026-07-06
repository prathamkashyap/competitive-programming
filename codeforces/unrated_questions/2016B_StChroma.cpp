#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        for(int i = x-1; i >= 0; --i) cout << i << " ";
        for(int i = n-1; i >= x; --i){
            cout << i;
            if(i != x) cout << " ";
        }
        cout << "\n";
    }
}
