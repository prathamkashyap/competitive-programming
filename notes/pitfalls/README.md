# ⚠️ Common Pitfalls 🚨

Practical mistakes that cost contests - off-by-one errors, overflow issues, recursion depth, and other gotchas I've learned the hard way.

---

## 📋 Available Pitfall Notes

| 🎯 Note | 📖 Description | ⚠️ Focus |
| :--- | :--- | :--- |
| [Binary Search Invariants](binary-search-invariants.md) | Common mistakes in binary search implementation | Loop conditions, monotonicity, search bounds |
| [Complexity Mistakes](complexity-mistakes.md) | Misjudging complexity and time limits | Wrong complexity, hidden constants, optimization |
| [DP State Definition](dp-state-definition.md) | Incorrect state design in DP | State design, transitions, base cases, space optimization |
| [Graph Traversal Mistakes](graph-traversal-mistakes.md) | BFS/DFS implementation errors | Parent tracking, disconnected graphs, initialization |
| [Off-by-One Errors](off-by-one-errors.md) | Indexing and boundary mistakes | Array indexing, loop conditions, prefix sums |
| [Overflow and Integer Types](overflow-and-integer-types.md) | Integer overflow and type selection | Integer overflow, type selection, negative modulo |
| [Recursion and Stack Depth](recursion-and-stack-depth.md) | Stack overflow and recursion limits | Stack overflow, infinite recursion, memoization |

---

## 🧠 How to Use

### 📋 Before Coding
Review pitfalls relevant to your approach - save time by avoiding known mistakes

### 🐛 When Debugging
Check if your bug matches a known pitfall - common patterns repeat

### ✅ For Review
Use as a checklist of common mistakes before submitting

---

## 💡 Quick Reference

| ⚠️ Issue | 🔍 Check | 💡 Fix |
| :--- | :--- | :--- |
| Overflow | Large multiplications? | Use `long long` or modular arithmetic |
| Off-by-one | Loop bounds? | Use `<` vs `<=` carefully |
| Stack overflow | Deep recursion? | Increase recursion limit or use iterative |
| TLE | Complexity? | Optimize or use better algorithm |
| WA | Edge cases? | Test n=0, n=1, max constraints |

---

## 📚 Related

- [Complexity Cheatsheet](../cheatsheets/complexity_cheatsheet.md) ⏱️
- [Implementation Tricks](../cheatsheets/implementation_tricks.md) 🔧
- [../complexity_and_limits.md](../complexity_and_limits.md) 📊

---

[← Back to Notes](../README.md)
