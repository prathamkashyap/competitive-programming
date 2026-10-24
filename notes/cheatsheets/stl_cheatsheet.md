# STL Cheatsheet

Useful STL containers and algorithms I use in competitive programming.

## Priority Queue

```cpp
#include <queue>
priority_queue<int> pq; // max-heap
priority_queue<int, vector<int>, greater<int>> pq; // min-heap
pq.push(x);
pq.pop();
pq.top();
pq.size();
```

## Set / Multiset

```cpp
#include <set>
set<int> s; // ordered, unique
multiset<int> ms; // ordered, duplicates
s.insert(x);
s.erase(x);
s.find(x); // iterator or s.end()
s.lower_bound(x); // first >= x
s.upper_bound(x); // first > x
s.count(x); // 0 or 1 for set, count for multiset
```

## Map / Unordered Map

```cpp
#include <map>
#include <unordered_map>
map<int, int> m; // ordered (O(log n))
unordered_map<int, int> um; // unordered (O(1) average)
m[key] = value;
m.find(key);
m.count(key);
```

## Sort and Binary Search

```cpp
#include <algorithm>
#include <vector>
sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>()); // descending
sort(v.begin(), v.end(), [](int a, int b) { return a % mod < b % mod; }); // custom
lower_bound(v.begin(), v.end(), x); // first >= x
upper_bound(v.begin(), v.end(), x); // first > x
binary_search(v.begin(), v.end(), x); // bool: exists?
```

## String Streams

```cpp
#include <sstream>
stringstream ss("1 2 3");
int x; ss >> x;
string s; ss >> s;
ss.str(); // clear
ss << x << " " << y;
```

## Partial Sum

```cpp
#include <numeric>
partial_sum(v.begin(), v.end(), v.begin());
partial_sum(v.begin(), v.end(), v.begin(), 0); // with initial value
```

---

[← Back to Notes](../README.md)
