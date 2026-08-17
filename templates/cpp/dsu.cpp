/**
 * @file dsu.cpp
 * @brief Disjoint Set Union (DSU) / Union-Find with Path Compression & Union by Size
 */

#include <vector>
#include <numeric>

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> size;
    int num_components;

public:
    explicit DSU(int n) : parent(n + 1), size(n + 1, 1), num_components(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            // Union by size
            if (size[root_i] < size[root_j])
                std::swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
            num_components--;
            return true;
        }
        return false;
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    int get_size(int i) {
        return size[find(i)];
    }

    int count_components() const {
        return num_components;
    }
};
