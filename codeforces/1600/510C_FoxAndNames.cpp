#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> names(n);

    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);

    for (int i = 0; i < n - 1; i++) {
        const string& a = names[i];
        const string& b = names[i + 1];

        int j = 0;
        int limit = min(a.size(), b.size());

        while (j < limit && a[j] == b[j]) {
            j++;
        }

        if (j == limit) {
            if (a.size() > b.size()) {
                cout << "Impossible\n";
                return 0;
            }
        } else {
            int u = a[j] - 'a';
            int v = b[j] - 'a';

            adj[u].push_back(v);
            indegree[v]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    string answer;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        answer += char('a' + u);

        for (int v : adj[u]) {
            indegree[v]--;

            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (answer.size() != 26) {
        cout << "Impossible\n";
    } else {
        cout << answer << '\n';
    }

    return 0;
}