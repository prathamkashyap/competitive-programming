#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        long long a, b, k;
        cin >> a >> b >> k;
        
        // Case 1: Can reach (0,0) in one move
        if (max(a, b) <= k) {
            cout << 1 << "\n";
            continue;
        }
        
        // Case 2: Can use repeated moves with same direction ratio
        long long g = gcd(a, b);
        if (max(a/g, b/g) <= k) {
            cout << 1 << "\n";
            continue;
        }
        
        // Case 3: Need at least 2 different moves
        cout << 2 << "\n";
    }
    return 0;
}