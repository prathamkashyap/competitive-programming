# 🏆 Codeforces Problem Solutions

[![Codeforces](https://img.shields.io/badge/Platform-Codeforces-1F8ACB?style=for-the-badge&logo=codeforces&logoColor=white)](https://codeforces.com/profile/prathamkashyap)
[![Profile](https://img.shields.io/badge/Profile-prathamkashyap-blue?style=for-the-badge)](https://codeforces.com/profile/prathamkashyap)
[![Rating](https://img.shields.io/badge/Rating-815%20(Newbie)-lightgrey?style=for-the-badge)](https://codeforces.com/profile/prathamkashyap)
[![Repository Solutions](https://img.shields.io/badge/Repository%20Solutions-322-brightgreen?style=for-the-badge)](https://github.com/prathamkashyap/competitive-programming/tree/main/codeforces)
[![Language](https://img.shields.io/badge/Language-C++20-blue?style=for-the-badge&logo=c%2B%2B)](https://github.com/prathamkashyap/competitive-programming/tree/main/codeforces)

[![Accepted Problems](https://img.shields.io/badge/Accepted%20Problems-306-1F8ACB?style=flat-square&logo=codeforces&logoColor=white)](https://codeforces.com/profile/prathamkashyap)
[![Last Year](https://img.shields.io/badge/Last%20Year-280%20solved-2EA44F?style=flat-square&logo=codeforces&logoColor=white)](https://codeforces.com/profile/prathamkashyap)
[![Last Month](https://img.shields.io/badge/Last%20Month-100%20solved-F2C94C?style=flat-square&logo=codeforces&logoColor=black)](https://codeforces.com/profile/prathamkashyap)
[![Streak](https://img.shields.io/badge/Longest%20Streak-68%20days-8E44AD?style=flat-square&logo=codeforces&logoColor=white)](https://codeforces.com/profile/prathamkashyap)

This directory houses categorized solutions to problems from **Codeforces** contests (Div. 1, Div. 2, Div. 3, Div. 4, Educational Rounds, and Global Rounds), structured systematically by problem difficulty rating.

---

## 👤 Profile Details

- **Handle**: [@prathamkashyap](https://codeforces.com/profile/prathamkashyap)
- **Current Rating**: `815` (Newbie)
- **Max Rating**: `815`
- **Unique accepted problems in Codeforces API**: `306` (checked 2026-09-04)
- **C++ solutions in this repository**: `322`, including `30` unrated-question files
- **Recent activity**: `280` problems solved in the last year, `100` in the last month
- **Longest active streak**: `68` days

---

## 📊 Difficulty Distribution

| Rating Folder | Difficulty Tier | Solutions | Key Topics & Patterns |
| :--- | :--- | :---: | :--- |
| [`800/`](800/) | **Newbie / Beginner** | **83** | Basic I/O, Simulation, Greedy, Strings, Math |
| [`900/`](900/) | **Newbie / Basic** | **36** | Brute Force, Math, Two Pointers, Strings, Sorting |
| [`1000/`](1000/) | **Pupil** | **44** | Constructive Algorithms, Simple Data Structures, Binary Search |
| [`1100/`](1100/) | **Pupil** | **39** | Number Theory, Prefix Sums, Bitwise Tricks, Greedy |
| [`1200/`](1200/) | **Pupil / Specialist** | **41** | Basic DP, Combinatorics, Sliding Window, Greedy Proofs |
| [`1300/`](1300/) | **Specialist** | **34** | Modular Arithmetic, Bitmasking, Binary Search on Answer, Graph Basics |
| [`1400/`](1400/) | **Specialist** | **5** | Two Pointers, Medium DP, Constructive Strategies |
| [`1500/`](1500/) | **Specialist / Expert** | **7** | BFS/DFS, Trees, Priority Queues, Coordinate Compression |
| [`1600/`](1600/) | **Expert** | **0** | Advanced Greedy, Dynamic Programming, Tree Properties |
| [`1700/`](1700/) | **Expert** | **1** | Range Queries, Segment Trees, Graph Theory |
| [`1800/`](1800/) | **Expert / Candidate Master** | **1** | Disjoint Set Union, Game Theory, Advanced DP |
| [`2000/`](2000/) | **Candidate Master** | **1** | Complex DP, State Space Reduction, Math Invariants |
| [`unrated_questions/`](unrated_questions/) | **Contest / Live** | **30** | Live Contests, Div. 3/4 A-D, Virtual Contests |

---

## 🏷️ Naming Convention

Files are named following standard Codeforces problem identifiers for easy search and reference:

```
<Rating>/<ProblemID>_<ProblemName>.<ext>
```

**Examples:**
- `800/4A_Watermelon.cpp` $\rightarrow$ Problem 4A (Watermelon)
- `1000/69A_YoungPhysicist.cpp` $\rightarrow$ Problem 69A (Young Physicist)
- `1300/230B_T-primes.cpp` $\rightarrow$ Problem 230B (T-primes)
- `1500/580C_KefaandPark.cpp` $\rightarrow$ Problem 580C (Kefa and Park)

---

## 🧠 Strategic Tips for Codeforces

1. **Read Constraints First**: The constraint on $N$ reveals the intended time complexity:
   - $N \le 10 \rightarrow O(N!)$ or $O(2^N \cdot N)$
   - $N \le 20 \rightarrow O(2^N)$
   - $N \le 500 \rightarrow O(N^3)$ (Floyd-Warshall, 3D DP)
   - $N \le 5000 \rightarrow O(N^2)$ (2D DP, Nested Loops)
   - $N \le 2 \cdot 10^5 \rightarrow O(N \log N)$ or $O(N)$ (Sorting, Segment Trees, Two Pointers, Sieve)
   - $N \le 10^9 \rightarrow O(\sqrt{N})$ or $O(\log N)$ (Prime checking, Binary search, Math)

2. **Watch for 64-bit Overflow**: Any product of two values $\ge 10^5$ or sum of arrays with values $\ge 10^9$ can exceed $2^{31}-1 \approx 2 \cdot 10^9$. Always use `long long` (or `int64_t`).

3. **Fast I/O is Mandatory**: Ensure `cin.tie(NULL); ios_base::sync_with_stdio(false);` is invoked at the start of `main()`.

---

[← Back to Main Repository](../README.md)
