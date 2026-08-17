/**
 * @file fenwick_tree.cpp
 * @brief Binary Indexed Tree (Fenwick Tree) for Point Updates and Prefix/Range Queries
 */

#include <vector>

template <typename T>
class FenwickTree {
private:
    int n;
    std::vector<T> tree;

public:
    explicit FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    // Add val to element at 1-based index idx
    void add(int idx, T val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    // Prefix sum in range [1, idx]
    T query(int idx) {
        T sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }

    // Range sum query in [l, r] (1-based)
    T query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
