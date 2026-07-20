
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> adj(n);

    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> seen(n, false);
    ll total = 0;

    for (int i = 0; i < n; i++) {
        if (seen[i]) {
            continue;
        }

        int size = 0;
        stack<int> st;
        st.push(i);
        seen[i] = true;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            size++;

            for (int v : adj[u]) {
                if (!seen[v]) {
                    seen[v] = true;
                    st.push(v);
                }
            }
        }

        total += 1LL * size * (size - 1) / 2;
    }

    ll pairs = 1LL * n * (n - 1) / 2;
    cout << pairs - total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
