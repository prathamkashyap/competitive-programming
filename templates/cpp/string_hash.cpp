#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 31;

long long power(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<long long> compute_prefix_hashes(string s) {
    int n = s.length();
    vector<long long> pref(n + 1, 0);
    long long p = 1;
    for (int i = 0; i < n; i++) {
        pref[i+1] = (pref[i] * BASE + s[i]) % MOD;
        p = p * BASE % MOD;
    }
    return pref;
}

long long get_hash(vector<long long>& pref, int l, int r) {
    long long hash = (pref[r+1] - pref[l] * power(BASE, r - l + 1, MOD)) % MOD;
    return (hash + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    auto pref = compute_prefix_hashes(s);
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get_hash(pref, l, r) << '\n';
    }
    
    return 0;
}
