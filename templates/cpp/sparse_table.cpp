#include <bits/stdc++.h>
using namespace std;

const int LOGN = 20;
const int MAXN = 2e5 + 5;
int logg[MAXN];
int st[MAXN][LOGN];
int a[MAXN];

void precompute() {
    logg[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        logg[i] = logg[i/2] + 1;
    }
}

void build(int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
}

int query(int l, int r) {
    int len = r - l + 1;
    int k = logg[len];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    precompute();
    build(n);
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    
    return 0;
}
