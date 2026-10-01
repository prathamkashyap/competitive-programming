#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Round {
    string name;
    long long score;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Round> rounds(N);
    map<string, long long> totalScore;

    for (int i = 0; i < N; i++) {
        cin >> rounds[i].name >> rounds[i].score;
        totalScore[rounds[i].name] += rounds[i].score;
    }

    long long maximumScore = -1e18;

    for (const auto& [name, score] : totalScore) {
        maximumScore = max(maximumScore, score);
    }

    map<string, long long> currentScore;

    for (const auto& round : rounds) {
        currentScore[round.name] += round.score;

        if (currentScore[round.name] >= maximumScore &&
            totalScore[round.name] == maximumScore) {
            cout << round.name << '\n';
            return 0;
        }
    }

    return 0;
}