# 🔢 Number Theory & Modular Arithmetic

## 1. Modular Arithmetic Axioms

For a modulus $M$:
- $(a + b) \pmod M = ((a \bmod M) + (b \bmod M)) \pmod M$
- $(a - b) \pmod M = ((a \bmod M) - (b \bmod M) + M) \pmod M$
- $(a \times b) \pmod M = ((a \bmod M) \times (b \bmod M)) \pmod M$
- $(a / b) \pmod M = (a \times b^{-1}) \pmod M$ (where $b^{-1}$ is the modular multiplicative inverse of $b$).

---

## 2. Modular Multiplicative Inverse

By Fermat's Little Theorem, if $M$ is prime:
$$a^{M-1} \equiv 1 \pmod M \implies a^{M-2} \equiv a^{-1} \pmod M$$

```cpp
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

long long modInverse(long long n, long long mod = 1e9 + 7) {
    return power(n, mod - 2, mod);
}
```

---

## 3. Combinatorics: $nCr \pmod M$

Precomputing factorials and inverse factorials up to $N = 2 \cdot 10^5$ allows $O(1)$ query time for combinations:

```cpp
const int MAXN = 200005;
const int MOD = 1e9 + 7;
long long fact[MAXN], invFact[MAXN];

void precompute() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAXN - 1] = modInverse(fact[MAXN - 1], MOD);
    for (int i = MAXN - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}
```

---

[← Back to Notes](README.md)
