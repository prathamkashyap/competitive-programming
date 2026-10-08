#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    long long health = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;

        health += x;
        minHeap.push(x);

        if (health < 0) {
            health -= minHeap.top();
            minHeap.pop();
        }
    }

    cout << minHeap.size() << '\n';

    return 0;
}