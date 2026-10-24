# ⚡ Complexity Cheatsheet 🧠

Quick reference for complexity analysis and time limit heuristics I use in contests.

---

## ⏱️ Operations per Second

- **$10^8$ operations** - Safe for 1 second on most judges
- **$10^7$ operations** - Safer margin for Python or complex operations
- **$10^9$ operations** - Risky, only for very simple operations

---

## 📊 Common Complexity Classes

| n | log n | n log n | n² | n³ | 2ⁿ |
|---|-------|---------|-----|-----|-----|
| 10³ | 10 | 10³ | 10⁶ | 10⁹ | ∞ |
| 10⁴ | 13 | 1.3×10⁴ | 10⁸ | ∞ | ∞ |
| 10⁵ | 17 | 1.7×10⁵ | 10¹⁰ | ∞ | ∞ |
| 10⁶ | 20 | 2×10⁶ | ∞ | ∞ | ∞ |

---

## ⏰ Time Limit Heuristics

- **1 second** (TL=1s): ~10⁸ simple operations in C++, ~10⁷ in Python
- **2 seconds** (TL=2s): ~2× above
- **Multi-testcase**: Divide operations by number of test cases

---

## 🔢 Data Type Limits

| Type | Range | Max Value |
|------|-------|-----------|
| int | 32-bit signed | ±2×10⁹ |
| long long | 64-bit signed | ±9×10¹⁸ |
| __int128 | 128-bit signed | ±10³⁸ |

**Rule of thumb:**
- Use `long long` for values up to 10¹⁸
- Use `__int128` for values up to 10³⁸ (if compiler supports)
- Use modular arithmetic to avoid overflow

---

## 💾 Memory Limits

- **256 MB** - ~6×10⁷ integers, ~10⁸ long longs
- **512 MB** - ~1.2×10⁸ integers, ~2×10⁸ long longs
- **1 GB** - ~2.4×10⁸ integers, ~4×10⁸ long longs

---

## 🔄 Common Constant Factors

- **Sorting**: n log n with log₂(n) ~ 20 for n=10⁶
- **DFS/BFS**: O(V + E), each node/edge visited once
- **Segment Tree**: 4n nodes for n elements
- **Fenwick Tree**: n nodes for n elements

---

## ⚠️ Hidden Constants

- **Modular operations**: division and modulo are slower than addition
- **String operations**: substring comparison is O(length)
- **Set/Map operations**: O(log n) average, O(n) worst case
- **Vector operations**: reallocation O(n) when capacity exceeded

---

## 💡 Quick Tips

- Always read constraints first
- Estimate operations before coding
- Use appropriate data types to avoid overflow
- Consider constant factors for tight limits

---

[← Back to Notes](../README.md)
