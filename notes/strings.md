# 🔗 Strings Algorithms 🎯

String algorithms and hashing for pattern matching and string problems.

---

## 🔄 Rolling Hash

```cpp
const int MOD = 1e9 + 7;
const int BASE = 31;

// Compute hash of string s[0..i]
long long hash = 0;
for (int i = 0; i < n; i++) {
    hash = (hash * BASE + s[i]) % MOD;
}

// Hash of substring s[l..r]
long long sub_hash = (pref[r+1] - pref[l] * pow(BASE, r-l+1)) % MOD;
```

---

## 🔍 KMP (Knuth-Morris-Pratt)

Computes prefix function for pattern matching in O(n + m).

```cpp
vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
```

---

## 📊 Z-Algorithm

Computes Z-array for pattern matching in O(n).

```cpp
vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
```

---

## 🌳 Trie

Prefix tree for strings, O(L) insert/search.

```cpp
struct TrieNode {
    TrieNode* children[26];
    bool is_end;
    
    TrieNode() {
        memset(children, 0, sizeof(children));
        is_end = false;
    }
};

void insert(TrieNode* root, string s) {
    TrieNode* node = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!node->children[idx]) {
            node->children[idx] = new TrieNode();
        }
        node = node->children[idx];
    }
    node->is_end = true;
}
```

---

## 🎯 When to Use

| 🎯 Problem | 🧩 Algorithm | ⏱️ Complexity |
| :--- | :--- | :--- |
| Substring comparison | Rolling hash | O(L) hash, O(1) compare |
| Pattern matching | KMP | O(N + M) |
| Pattern matching | Z-algorithm | O(N) |
| Dictionary / prefix matching | Trie | O(L) insert/search |

---

## 💡 Quick Tips

- Use rolling hash for O(1) substring comparison
- KMP is useful for single pattern search
- Trie is great for dictionary and prefix operations
- Always use modulo with rolling hash to avoid overflow

---

[← Back to Notes](../README.md)
