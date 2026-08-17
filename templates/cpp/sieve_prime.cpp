/**
 * @file sieve_prime.cpp
 * @brief Linear Sieve and Smallest Prime Factor (SPF) for O(log K) Prime Factorization
 */

#include <vector>
#include <map>

class Sieve {
public:
    int n;
    std::vector<int> spf; // Smallest Prime Factor
    std::vector<int> primes;
    std::vector<bool> is_prime;

    explicit Sieve(int limit) : n(limit), spf(limit + 1), is_prime(limit + 1, true) {
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++) spf[i] = i;

        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                spf[i] = i;
            }
            for (int p : primes) {
                if (p > spf[i] || (long long)i * p > n) break;
                is_prime[i * p] = false;
                spf[i * p] = p;
            }
        }
    }

    // Fast prime factorization in O(log x)
    std::vector<std::pair<int, int>> factorize(int x) {
        std::vector<std::pair<int, int>> factors;
        while (x > 1) {
            int p = spf[x];
            int count = 0;
            while (x % p == 0) {
                count++;
                x /= p;
            }
            factors.emplace_back(p, count);
        }
        return factors;
    }
};
