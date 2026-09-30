#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<pair<int, int>> exams(N);

    for (int i = 0; i < N; i++) {
        cin >> exams[i].first >> exams[i].second;
    }

    sort(exams.begin(), exams.end());

    int lastDay = 0;

    for (int i = 0; i < N; i++) {
        int a = exams[i].first;
        int b = exams[i].second;

        if (b >= lastDay) {
            lastDay = b;
        } else {
            lastDay = a;
        }
    }

    return lastDay;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << '\n';

    return 0;
}