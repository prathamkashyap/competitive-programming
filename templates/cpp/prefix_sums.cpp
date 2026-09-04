#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

struct PrefixSum {
    vector<int64> prefix;

    explicit PrefixSum(const vector<int64>& values) : prefix(values.size() + 1, 0) {
        for (size_t index = 0; index < values.size(); ++index) {
            prefix[index + 1] = prefix[index] + values[index];
        }
    }

    int64 range_sum(int left, int right) const {
        if (left > right || left < 0 || right >= static_cast<int>(prefix.size()) - 1) {
            return 0;
        }
        return prefix[right + 1] - prefix[left];
    }
};

struct DifferenceArray {
    vector<int64> difference;

    explicit DifferenceArray(int size) : difference(size + 1, 0) {}

    void add_range(int left, int right, int64 value) {
        difference[left] += value;
        if (right + 1 < static_cast<int>(difference.size())) {
            difference[right + 1] -= value;
        }
    }

    vector<int64> build() const {
        vector<int64> values(difference.size() - 1);
        int64 current = 0;
        for (size_t index = 0; index < values.size(); ++index) {
            current += difference[index];
            values[index] = current;
        }
        return values;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
