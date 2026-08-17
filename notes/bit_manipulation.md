# 💻 Bit Manipulation & Bitmasking Hacks

## 1. Essential Bit Operations

| Operation | Syntax | Description |
| :--- | :--- | :--- |
| **Check if $k$-th bit is set** | `(n & (1 << k)) != 0` | Tests if bit $k$ is 1 |
| **Set $k$-th bit** | `n \| (1 << k)` | Turns bit $k$ to 1 |
| **Clear $k$-th bit** | `n & ~(1 << k)` | Turns bit $k$ to 0 |
| **Toggle $k$-th bit** | `n ^ (1 << k)` | Flips bit $k$ |
| **Extract lowest set bit (LSB)** | `n & (-n)` | Returns the lowest power of 2 dividing $n$ |
| **Clear lowest set bit** | `n & (n - 1)` | Clears the rightmost set bit |
| **Check if power of 2** | `n > 0 && (n & (n - 1)) == 0` | True if $n = 2^k$ |

---

## 2. GCC Built-in Functions

```cpp
// 32-bit integers
__builtin_popcount(x);  // Count set bits (number of 1s)
__builtin_clz(x);       // Count leading zeros
__builtin_ctz(x);       // Count trailing zeros

// 64-bit integers (long long)
__builtin_popcountll(x);
__builtin_clzll(x);
__builtin_ctzll(x);
```

---

## 3. Submask Iteration in $O(3^N)$

Iterate over all submasks of a mask efficiently:

```cpp
for (int mask = 0; mask < (1 << n); mask++) {
    for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
        // Process submask
    }
}
```

---

[← Back to Notes](README.md)
