#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, int color,
         const vector<vector<int>>& graph,
         vector<int>& colorOf,
         long long& cnt0,
         long long& cnt1) {
    colorOf[node] = color;

    if (color == 0) {
        cnt0++;
    } else {
        cnt1++;
    }

    for (int next : graph[node]) {
        if (next == parent) {
            continue;
        }

        dfs(next, node, 1 - color, graph, colorOf, cnt0, cnt1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> graph(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        --u;
        --v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> color(N, -1);

    long long cnt0 = 0;
    long long cnt1 = 0;

    dfs(0, -1, 0, graph, color, cnt0, cnt1);

    cout << cnt0 * cnt1 - (N - 1) << '\n';

    return 0;
}