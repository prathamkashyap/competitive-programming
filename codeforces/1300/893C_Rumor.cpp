#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, const vector<int>& cost,
         vector<bool>& visited, long long& minimum) {
    visited[node] = true;
    minimum = min(minimum, (long long)cost[node]);

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next, graph, cost, visited, minimum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> cost(N);

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    vector<vector<int>> graph(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        --u;
        --v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N, false);
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            long long minimum = cost[i];
            dfs(i, graph, cost, visited, minimum);
            answer += minimum;
        }
    }

    cout << answer << '\n';

    return 0;
}