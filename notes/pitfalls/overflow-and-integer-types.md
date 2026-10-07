# Overflow and Integer Types

## Common Mistakes

### 1. Not Using Long Long for Accumulation
```cpp
// WRONG
int sum = 0;
for (int i = 0; i < n; i++) {
    sum += a[i];  // Overflow if a[i] up to 10^9 and n up to 10^5
}

// CORRECT
long long sum = 0;
for (int i = 0; i < n; i++) {
    sum += a[i];
}
```

### 2. Mid Calculation Overflow in Binary Search
```cpp
// WRONG
int mid = (lo + hi) / 2;  // Overflow if lo + hi > INT_MAX

// CORRECT
int mid = lo + (hi - lo) / 2;
```

### 3. Multiplication Overflow
```cpp
// WRONG
int result = a * b;  // Overflow if a and b are large

// CORRECT
long long result = (long long)a * b;
```

### 4. Modulo on Negative Numbers
```cpp
// WRONG
int x = -5;
int mod = 7;
int result = x % mod;  // Result is -5, not 2

// CORRECT
int result = ((x % mod) + mod) % mod;
```

### 5. Integer Division vs Floating Point
```cpp
// WRONG
double result = 5 / 2;  // Result is 2.0, not 2.5

// CORRECT
double result = 5.0 / 2;  // Result is 2.5
```

## Type Guidelines

- Use `int` for values up to ~2×10^9
- Use `long long` for values up to ~9×10^18
- Use `long double` for high-precision floating point
- Always use `long long` for sums, products, or intermediate calculations
- Check constraints before choosing types

## Common Constraints

- `int`: 32-bit, range ~[-2×10^9, 2×10^9]
- `long long`: 64-bit, range ~[-9×10^18, 9×10^18]
- __int128: 128-bit, range ~[-10^38, 10^38] (compiler-specific)

## When to Use Each

| Constraint | Type |
|-----------|------|
| n ≤ 10^9, values ≤ 10^9 | int |
| n ≤ 10^5, values ≤ 10^9 | long long for sums |
| n ≤ 10^18 | long long |
| Products of large numbers | long long or __int128 |
| Floating point with precision | long double |

## Detection

- **WA on large inputs**: Likely overflow
- **Negative answers when expecting positive**: Integer overflow wraps around
- **Sanity check**: If answer seems impossibly large/small, check types

## Reference

See [notes/complexity_and_limits.md](../complexity_and_limits.md) for more on limits and operations per second.
