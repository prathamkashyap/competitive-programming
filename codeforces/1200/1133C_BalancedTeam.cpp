#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int N;
    cin >> N;

    vector<int> skills(N);

    for (int i = 0; i < N; i++) {
        cin >> skills[i];
    }

    sort(skills.begin(), skills.end());

    int left = 0;
    int answer = 0;

    for (int right = 0; right < N; right++) {
        while (skills[right] - skills[left] > 5) {
            left++;
        }

        answer = max(answer, right - left + 1);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << '\n';

    return 0;
}