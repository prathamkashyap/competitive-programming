#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

constexpr int64 MOD = 1'000'000'007;

int64 mod_pow(int64 base, int64 exponent, int64 mod = MOD) {
    base %= mod;
    int64 result = 1 % mod;
    while (exponent > 0) {
        if (exponent & 1) {
            result = static_cast<int64>((static_cast<i128>(result) * base) % mod);
        }
        base = static_cast<int64>((static_cast<i128>(base) * base) % mod);
        exponent >>= 1;
    }
    return result;
}

int64 mod_inverse_prime(int64 value, int64 mod = MOD) {
    return mod_pow(value, mod - 2, mod);
}

struct ModCombinations {
    vector<int64> factorial;
    vector<int64> inverse_factorial;
    int64 mod;

    ModCombinations(int maximum_n, int64 modulus = MOD) :
        factorial(maximum_n + 1, 1),
        inverse_factorial(maximum_n + 1, 1),
        mod(modulus) {
        for (int i = 1; i <= maximum_n; ++i) {
            factorial[i] = static_cast<int64>(
                (static_cast<i128>(factorial[i - 1]) * i) % mod);
        }
        inverse_factorial[maximum_n] = mod_inverse_prime(factorial[maximum_n], mod);
        for (int i = maximum_n; i > 0; --i) {
            inverse_factorial[i - 1] = static_cast<int64>(
                (static_cast<i128>(inverse_factorial[i]) * i) % mod);
        }
    }

    int64 choose(int n, int r) const {
        if (r < 0 || r > n || n >= static_cast<int>(factorial.size())) {
            return 0;
        }
        return static_cast<int64>(
            (static_cast<i128>(factorial[n]) * inverse_factorial[r] % mod) *
            inverse_factorial[n - r] % mod);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Keep the template ready to copy; add problem-specific input here.
    return 0;
}
