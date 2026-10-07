# Hashing Pattern

## When to Recognize

Problems involving:
- Frequency counting
- O(1) lookups and membership tests
- Grouping elements by properties
- Duplicate detection
- Substring matching (rolling hash)

## Core Idea

Map keys to values using hash functions for fast average-case operations. Hash maps and sets provide O(1) average-case insert, lookup, and delete.

## Common Complexity

- **Array/linear search**: O(N)
- **Hash map operations**: O(1) average, O(N) worst-case (collisions)

## Common Variations

### Frequency Counting
Count occurrences of elements.

**Pattern:**
```cpp
unordered_map<int, int> freq;
for (int x : a) {
    freq[x]++;
}
```

### Lookup and Membership
Check if element exists or belongs to a set.

**Pattern:**
```cpp
unordered_set<int> seen;
for (int x : a) {
    if (seen.count(x)) {
        // duplicate
    }
    seen.insert(x);
}
```

### Grouping by Property
Group elements sharing a characteristic.

**Pattern:**
```cpp
unordered_map<string, vector<int>> groups;
for (int i = 0; i < n; i++) {
    string key = compute_key(a[i]);
    groups[key].push_back(i);
}
```

### Rolling Hash (String Matching)
Compute hash of substrings efficiently.

**Pattern:**
```cpp
const long long MOD = 1e9 + 7;
const long long BASE = 31;

vector<long long> prefix_hash(n + 1, 0);
vector<long long> power(n + 1, 1);
for (int i = 0; i < n; i++) {
    prefix_hash[i + 1] = (prefix_hash[i] * BASE + s[i]) % MOD;
    power[i + 1] = (power[i] * BASE) % MOD;
}

long long get_hash(int l, int r) {
    return (prefix_hash[r + 1] - prefix_hash[l] * power[r - l + 1] % MOD + MOD) % MOD;
}
```

## Common Pitfalls

- **Hash collisions**: Different keys map to same hash (rare with good hash function)
- **Unordered iteration**: Hash maps don't guarantee order
- **Memory overhead**: Hash maps use more memory than arrays
- **Worst-case O(N)**: Many collisions can degrade to O(N) per operation
- **Custom hash needed**: For custom structs, need to define hash function

## Custom Hash for Structs

```cpp
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

unordered_map<pair<int, int>, int, PairHash> mp;
```

## Alternatives

- **Sorting**: O(N log N) but deterministic and no memory overhead
- **Coordinate compression**: Map values to indices, use array
- **Tree-based maps**: O(log N) worst-case, ordered iteration

## Representative Problems

- Two-sum with hash map
- Group anagrams
- Substring search with rolling hash
- Duplicate detection

## Related Patterns

- [Arrays](arrays.md)
- [Sliding Window](sliding-window.md) - Often uses hash maps for frequency counting
