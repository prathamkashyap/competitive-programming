#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> minHeap;
    ll health = 0;

    for (int i = 0; i < n; i++) {
        ll x;
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