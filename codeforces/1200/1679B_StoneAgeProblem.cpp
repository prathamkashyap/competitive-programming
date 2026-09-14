#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> value(N + 1);
    vector<int> updateTime(N + 1, 0);

    long long sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> value[i];
        sum += value[i];
    }

    long long lastValue = 0;
    int lastSetTime = -1;

    for (int query = 1; query <= Q; query++) {
        int type;
        cin >> type;

        if (type == 1) {
            int i;
            long long x;
            cin >> i >> x;

            long long currentValue;

            if (updateTime[i] > lastSetTime) {
                currentValue = value[i];
            } else {
                currentValue = lastValue;
            }

            sum -= currentValue;
            sum += x;

            value[i] = x;
            updateTime[i] = query;
        } else {
            long long x;
            cin >> x;

            sum = x * N;
            lastValue = x;
            lastSetTime = query;
        }

        cout << sum << '\n';
    }

    return 0;
}