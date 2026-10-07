#include <iostream>
#include <vector>
using namespace std;

long long choose2(long long x) {
    return x * (x - 1) / 2;
}

long long solve() {
    int A, B, K;
    cin >> A >> B >> K;

    vector<int> boys(K);
    vector<int> girls(K);

    vector<int> boyCount(A + 1, 0);
    vector<int> girlCount(B + 1, 0);

    for (int i = 0; i < K; i++) {
        cin >> boys[i];
        boyCount[boys[i]]++;
    }

    for (int i = 0; i < K; i++) {
        cin >> girls[i];
        girlCount[girls[i]]++;
    }

    long long answer = choose2(K);

    for (int i = 1; i <= A; i++) {
        answer -= choose2(boyCount[i]);
    }

    for (int i = 1; i <= B; i++) {
        answer -= choose2(girlCount[i]);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << '\n';
    }

    return 0;
}