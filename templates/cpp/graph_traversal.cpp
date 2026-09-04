#include <bits/stdc++.h>
using namespace std;

using Edge = pair<int, int>;

vector<int> bfs(const vector<vector<int>>& graph, int source) {
    vector<int> distance(graph.size(), -1);
    queue<int> pending;
    distance[source] = 0;
    pending.push(source);

    while (!pending.empty()) {
        int node = pending.front();
        pending.pop();
        for (int neighbor : graph[node]) {
            if (distance[neighbor] != -1) {
                continue;
            }
            distance[neighbor] = distance[node] + 1;
            pending.push(neighbor);
        }
    }
    return distance;
}

vector<int> topological_sort(const vector<vector<int>>& graph) {
    vector<int> indegree(graph.size());
    for (const auto& neighbors : graph) {
        for (int neighbor : neighbors) {
            ++indegree[neighbor];
        }
    }

    queue<int> ready;
    for (int node = 0; node < static_cast<int>(graph.size()); ++node) {
        if (indegree[node] == 0) {
            ready.push(node);
        }
    }

    vector<int> order;
    while (!ready.empty()) {
        int node = ready.front();
        ready.pop();
        order.push_back(node);
        for (int neighbor : graph[node]) {
            if (--indegree[neighbor] == 0) {
                ready.push(neighbor);
            }
        }
    }

    // An incomplete order means that the directed graph contains a cycle.
    if (order.size() != graph.size()) {
        return {};
    }
    return order;
}

vector<long long> dijkstra(const vector<vector<Edge>>& graph, int source) {
    constexpr long long infinity = numeric_limits<long long>::max() / 4;
    vector<long long> distance(graph.size(), infinity);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pending;
    distance[source] = 0;
    pending.push({0, source});

    while (!pending.empty()) {
        auto [current_distance, node] = pending.top();
        pending.pop();
        if (current_distance != distance[node]) {
            continue;
        }
        for (auto [neighbor, weight] : graph[node]) {
            long long candidate = current_distance + weight;
            if (candidate < distance[neighbor]) {
                distance[neighbor] = candidate;
                pending.push({candidate, neighbor});
            }
        }
    }
    return distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Vertices are zero-indexed; add problem-specific input here.
    return 0;
}
