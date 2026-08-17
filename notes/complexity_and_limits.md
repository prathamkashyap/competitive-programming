# ⏱️ Time Complexity, Space Complexity & Resource Limits

## 1. Rule of Thumb for Time Limits

Standard CP time limit is usually **1.0 second** to **2.0 seconds**.
Modern CPUs execute approximately **$10^8$ basic operations per second** in C++.

| Constraint on $N$ | Maximum Feasible Time Complexity | Typical Algorithms / Approaches |
| :---: | :---: | :--- |
| $N \le 10$ | $O(N!)$ | Permutations, Brute Force |
| $N \le 20$ | $O(2^N \cdot N)$ or $O(2^N)$ | Bitmask DP, Meet in the Middle, Subsets |
| $N \le 100$ | $O(N^4)$ | Brute Force 4-loops |
| $N \le 500$ | $O(N^3)$ | Floyd-Warshall, Matrix Multiplication, 3D DP |
| $N \le 5000$ | $O(N^2)$ | 2D Dynamic Programming, Nested Loops |
| $N \le 2 \cdot 10^5$ | $O(N \log N)$ or $O(N)$ | Sorting, Segment Tree, Binary Search, Two Pointers |
| $N \le 10^7$ | $O(N)$ | Simple linear scan, Linear Sieve, Prefix sums |
| $N \le 10^9$ | $O(\sqrt{N})$ or $O(\log N)$ | Prime testing, Binary search, Euclidean GCD |
| $N \le 10^{18}$ | $O(\log N)$ or $O(1)$ | Matrix Exponentiation, Fast Modulo Exponentiation |

---

## 2. Integer Types and Limits

| Type | Bits | Approximate Range | Max Value |
| :--- | :---: | :--- | :--- |
| `int` | 32 | $-2 \cdot 10^9$ to $2 \cdot 10^9$ | $2^{31}-1 \approx 2.14 \times 10^9$ |
| `unsigned int` | 32 | $0$ to $4 \cdot 10^9$ | $2^{32}-1 \approx 4.29 \times 10^9$ |
| `long long` | 64 | $-9 \cdot 10^{18}$ to $9 \cdot 10^{18}$ | $2^{63}-1 \approx 9.22 \times 10^{18}$ |
| `unsigned long long`| 64 | $0$ to $1.8 \cdot 10^{19}$ | $2^{64}-1 \approx 1.84 \times 10^{19}$ |
| `__int128` (GCC) | 128 | $\approx \pm 1.7 \cdot 10^{38}$ | Safe for multiplying two `long long` values |

> ⚠️ **Common Bug**: `int a = 1e9, b = 1e9; long long c = a * b;` will overflow before assigning because `a * b` is computed as a 32-bit integer. Always cast: `long long c = (long long)a * b;` or `1LL * a * b`.

---

## 3. Memory Limits

Typical CP memory limit is **256 MB** or **512 MB**.

- $1\text{ MB} \approx 10^6\text{ bytes}$
- An array of $10^7$ `int`s $\approx 40\text{ MB}$ (since `int` is 4 bytes).
- An array of $10^7$ `long long`s $\approx 80\text{ MB}$ (since `long long` is 8 bytes).
- Keep 2D arrays within limits: $1000 \times 1000$ `int`s $\approx 4\text{ MB}$, but $5000 \times 5000$ `int`s $\approx 100\text{ MB}$.

---

[← Back to Notes](README.md)
