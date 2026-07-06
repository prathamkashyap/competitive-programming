#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }
    
    int maxScore = scores[0], minScore = scores[0];
    int amazing = 0;
    
    for (int i = 1; i < n; ++i) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
            amazing++;
        } else if (scores[i] < minScore) {
            minScore = scores[i];
            amazing++;
        }
    }
    
    cout << amazing << '\n';
    return 0;
}
