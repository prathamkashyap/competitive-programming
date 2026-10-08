#include <iostream>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return;
        }

        if (size[a] < size[b]) {
            swap(a, b);
        }

        parent[b] = a;
        size[a] += size[b];
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    DSU dsu(N);

    for (int i = 0; i < M; i++) {
        int K;
        cin >> K;

        if (K == 0) {
            continue;
        }

        int first;
        cin >> first;

        for (int j = 1; j < K; j++) {
            int person;
            cin >> person;

            dsu.unite(first, person);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << dsu.getSize(i) << ' ';
    }

    cout << '\n';

    return 0;
}