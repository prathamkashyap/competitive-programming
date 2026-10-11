#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> graph(N+1);

  for (int i=0; i<M; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<bool> visited(N+1, false);
  int answer = 0;

  for (int i=1; i<=N; i++) {
    if (visited[i]) {
      continue;
    }
    
    queue<int> q;
    q.push(i);
    visited[i] = true;

    bool isCycle = true;

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      if (graph[u].size() != 2) {
        isCycle = false;
      }

      for (int v : graph[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }

    if (isCycle) {
      answer++;
    }
  }

  cout << answer << '\n';
  return 0;
}