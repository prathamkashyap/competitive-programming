# 📊 Codeforces Practice Profile

This note is derived from the C++ solutions currently stored under
`codeforces/`. The repository contains **322 files**; **315** filenames matched
an official Codeforces problem entry and **7** files were left out of the tag
summary because their filenames do not map cleanly to the public problemset
metadata. Counts below are **tag occurrences**, not mutually exclusive problem
counts: one problem may contribute to several categories.

## Category Distribution

| Category | Tagged occurrences | What this practice is building |
| :--- | ---: | :--- |
| Implementation | 145 | Translating observations into reliable code and handling edge cases |
| Math | 113 | Invariants, formulas, divisibility, and constructive reasoning |
| Greedy | 96 | Local choices, exchange arguments, and monotonic decisions |
| Brute Force | 53 | Constraint reading, enumeration, and pruning small search spaces |
| Sortings | 43 | Ordering as a way to expose structure and simplify decisions |
| Constructive Algorithms | 41 | Building valid outputs from parity, counts, and invariants |
| Dynamic Programming | 38 | State design, transitions, rolling state, and optimization |
| Strings | 36 | Frequency models, subsequences, transformations, and parsing |
| Number Theory | 31 | GCD, primes, factors, modular arithmetic, and divisibility |
| Binary Search | 28 | Sorted search and monotonic answer predicates |
| Data Structures | 27 | Efficient updates, queries, and state maintenance |
| Two Pointers | 22 | Ordered scans, windows, pair constraints, and amortized movement |
| DFS / Similar | 13 | Components, recursion, reachability, and state exploration |
| Combinatorics | 12 | Counting arrangements, choices, and modular combinations |
| Bitmasks | 10 | Subsets, flags, XOR structure, and compact state |
| Graphs | 7 | Adjacency models, connectivity, and traversal workflows |
| Geometry | 5 | Orientation, coordinates, and signed area reasoning |
| Games | 5 | Winning states, parity, and strategy invariants |
| Trees | 4 | Rooted traversal and hierarchical state |
| DSU | 4 | Dynamic connectivity and component merging |

## Practice Shape

The distribution points to a strong foundation in implementation, math, greedy
reasoning, and constructive problems. The natural next layer is to turn the
existing frequency into deeper reusable techniques:

1. **Greedy → proof**: write the invariant or exchange argument before coding.
2. **Math → reusable tools**: keep GCD, sieve, modular power, and factorization
   close at hand.
3. **Brute force → optimization**: identify the bottleneck, then upgrade with
   sorting, prefix sums, two pointers, or binary search.
4. **DP → state discipline**: name the state, transition, base case, and order
   of evaluation explicitly.
5. **Graphs → coverage**: expand from traversal into shortest paths, DSU, DAG
   DP, and tree lifting.

## Rating-Band Signals

| Repository band | Solutions | Dominant themes |
| :---: | ---: | :--- |
| 800 | 83 | Implementation, math, strings, constructive basics |
| 900 | 36 | Implementation, greedy, math, brute force |
| 1000 | 44 | Math, implementation, greedy, strings, constructive algorithms |
| 1100 | 39 | Implementation, greedy, sorting, DP, binary search |
| 1200 | 41 | Implementation, greedy, sorting, two pointers, DP |
| 1300 | 34 | Math, greedy, number theory, binary search, data structures |
| 1400+ | 14 | Graphs, DFS, DP, trees, shortest paths, binary search |
| Unrated | 30 | Greedy, math, DP, implementation, constructive problems |

The rating folders are a useful progression: consolidate the high-volume
800-1300 patterns while deliberately using the 1400+ and unrated problems to
practice graph modeling, proof quality, and multi-step state design.

## Suggested Revision Order

- [ ] Prefix sums and difference arrays
- [ ] Sliding windows and two pointers
- [ ] Greedy proofs and interval decisions
- [ ] Binary search on the answer
- [ ] DP state compression and reconstruction
- [ ] Graph traversal, DSU, and shortest paths
- [ ] Number theory toolkit and modular counting

[← Back to Notes](README.md)
