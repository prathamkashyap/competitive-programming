#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if (x < 2) return false;
    if (x % 2 == 0) return x == 2;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;

    int nextp = n + 1;
    while (!isPrime(nextp)) ++nextp;

    cout << (nextp == m ? "YES\n" : "NO\n");
    return 0;
}
