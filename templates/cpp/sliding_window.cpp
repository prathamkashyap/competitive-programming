#include <bits/stdc++.h>
using namespace std;

int longest_at_most_k_distinct(const vector<int>& values, int limit) {
    unordered_map<int, int> frequency;
    int left = 0;
    int best = 0;

    for (int right = 0; right < static_cast<int>(values.size()); ++right) {
        ++frequency[values[right]];
        while (static_cast<int>(frequency.size()) > limit) {
            if (--frequency[values[left]] == 0) {
                frequency.erase(values[left]);
            }
            ++left;
        }
        best = max(best, right - left + 1);
    }
    return best;
}

long long count_subarrays_at_most_sum(const vector<int>& values, long long limit) {
    if (limit < 0) {
        return 0;
    }

    long long answer = 0;
    long long current_sum = 0;
    int left = 0;
    for (int right = 0; right < static_cast<int>(values.size()); ++right) {
        current_sum += values[right];
        while (current_sum > limit) {
            current_sum -= values[left++];
        }
        answer += right - left + 1;
    }
    return answer;
}

long long count_subarrays_with_sum(const vector<int>& values, long long target) {
    unordered_map<long long, long long> seen{{0, 1}};
    long long prefix = 0;
    long long answer = 0;
    for (int value : values) {
        prefix += value;
        if (auto it = seen.find(prefix - target); it != seen.end()) {
            answer += it->second;
        }
        ++seen[prefix];
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
