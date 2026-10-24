# 🔧 Implementation Tricks ⚡

Common gotchas and techniques I've learned from contest mistakes.

---

## ⚠️ Off-by-One Errors

### Loop Conditions

```cpp
// Wrong: off-by-one
for (int i = 0; i <= n; i++)  // goes n+1 times

// Correct
for (int i = 0; i < n; i++)
```

### Prefix Sums

```cpp
// Range sum [l, r] (1-indexed)
// Wrong: sum[r] - sum[l-1]
// Correct: sum[r] - sum[l-1] for 1-indexed arrays
```

### Binary Search

```cpp
// Wrong: infinite loop on adjacent elements
while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check(mid)) hi = mid;
    else lo = mid + 1;
}

// Correct: ensure progress
while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) hi = mid;
    else lo = mid + 1;
}
```

---

## 💥 Overflow

### Integer Overflow

```cpp
// Wrong: (a + b) can overflow
long long sum = a + b;

// Correct: cast before operation
long long sum = (long long)a + b;
```

### Multiplication

```cpp
// Wrong: a * b can overflow before casting
long long prod = a * b;

// Correct: cast to larger type first
long long prod = (long long)a * b;
```

### Factorial

```cpp
// Wrong: 20! overflows 64-bit
// Use modular arithmetic instead
```

---

## 🗺️ Coordinate Compression

```cpp
// Sort unique values, map to 0..n-1
vector<int> vals = {5, 3, 9, 1};
sort(vals.begin(), vals.end());
vals.erase(unique(vals.begin(), vals.end()), vals.end());

// Map original to compressed
int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
```

---

## ➗ Modulo with Negative Numbers

```cpp
// Wrong: -5 % 3 = -2 in C++
// Correct: ((a % mod) + mod) % mod
int ans = ((a % mod) + mod) % mod;
```

---

## 📝 String Handling

### Empty String

```cpp
// Always check bounds before accessing
if (i < s.length() && s[i] == 'x') { ... }
```

### Substring Bounds

```cpp
// Wrong: s.substr(i, len) can go out of bounds
// Correct: ensure i + len <= s.length()
```

---

## 💡 Quick Tips

- Always use `long long` for intermediate calculations in DP
- Check array bounds before accessing
- Use modular arithmetic for large numbers
- Test edge cases: n=0, n=1, maximum constraints

---

[← Back to Notes](../README.md)
