/**
 * @file segment_tree.cpp
 * @brief Generic Segment Tree with Point Updates and Range Queries
 */

#include <vector>
#include <functional>

template <typename T>
class SegmentTree {
private:
    int n;
    std::vector<T> tree;
    T neutral;
    std::function<T(T, T)> merge;

    void build(const std::vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return neutral;
        if (l <= start && end <= r)
            return tree[node];
        int mid = start + (end - start) / 2;
        T p1 = query(2 * node, start, mid, l, r);
        T p2 = query(2 * node + 1, mid + 1, end, l, r);
        return merge(p1, p2);
    }

public:
    SegmentTree(const std::vector<T>& arr, T neutral_val, std::function<T(T, T)> merge_func)
        : n(arr.size()), neutral(neutral_val), merge(merge_func) {
        tree.resize(4 * n + 1);
        if (n > 0) build(arr, 1, 0, n - 1);
    }

    void update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }

    T query(int l, int r) {
        if (l > r || l < 0 || r >= n) return neutral;
        return query(1, 0, n - 1, l, r);
    }
};
