# Combinatorics

Counting formulas and modular arithmetic I use for contest problems.

## nCr Modulo

Precompute factorials and inverse factorials for O(1) nCr queries.

```cpp
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

long long fact[MAXN], inv_fact[MAXN];

long long power(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv_fact[MAXN-1] = power(fact[MAXN-1], MOD-2, MOD);
    for (int i = MAXN-2; i >= 0; i--) {
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n-r] % MOD;
}
```

## Catalan Numbers

C_n = (2n choose n) / (n+1) = number of valid parenthesis sequences, BSTs with n nodes.

```cpp
long long catalan(int n) {
    return nCr(2*n, n) * power(n+1, MOD-2, MOD) % MOD;
}
```

## Stars and Bars

Number of ways to distribute n identical items into k distinct boxes:
- Non-negative: C(n + k - 1, k - 1)
- Positive: C(n - 1, k - 1)

## Inclusion-Exclusion

|A ∪ B| = |A| + |B| - |A ∩ B|
|A ∪ B ∪ C| = |A| + |B| + |C| - |A∩B| - |A∩C| - |B∩C| + |A∩B∩C|

---

[← Back to Notes](../README.md)
