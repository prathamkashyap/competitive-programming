
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> values = a;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    int distinct = values.size();
    int changes = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            changes++;
        }
    }

    if (changes == distinct - 1) {
        cout << "YES\n";
        return;
    }

    vector<vector<pair<int, int>>> blocks(distinct);

    for (int i = 0; i < n;) {
        int j = i;

        while (j < n && a[j] == a[i]) {
            j++;
        }

        int id = lower_bound(
            values.begin(), values.end(), a[i]
        ) - values.begin();

        blocks[id].push_back({i, j - 1});
        i = j;
    }

    int target = -1;

    for (int i = 0; i < distinct; i++) {
        if (blocks[i].size() > 3) {
            cout << "NO\n";
            return;
        }

        if (blocks[i].size() > 1) {
            target = i;
        }
    }

    if (target == -1) {
        cout << "YES\n";
        return;
    }

    vector<int> candidates;

    for (auto [l, r] : blocks[target]) {
        for (int pos : {l - 1, l, l + 1, r - 1, r, r + 1}) {
            if (pos >= 0 && pos < n) {
                candidates.push_back(pos);
            }
        }
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(
        unique(candidates.begin(), candidates.end()),
        candidates.end()
    );

    auto check = [&](int x, int y) -> bool {
        if (x == y) {
            return false;
        }

        vector<int> edges = {x - 1, x, y - 1, y};

        sort(edges.begin(), edges.end());
        edges.erase(unique(edges.begin(), edges.end()), edges.end());

        int oldChanges = 0;

        for (int i : edges) {
            if (i >= 0 && i + 1 < n) {
                oldChanges += (a[i] != a[i + 1]);
            }
        }

        swap(a[x], a[y]);

        int newChanges = 0;

        for (int i : edges) {
            if (i >= 0 && i + 1 < n) {
                newChanges += (a[i] != a[i + 1]);
            }
        }

        swap(a[x], a[y]);

        return changes - oldChanges + newChanges == distinct - 1;
    };

    for (int x : candidates) {
        for (int y : candidates) {
            if (check(x, y)) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
