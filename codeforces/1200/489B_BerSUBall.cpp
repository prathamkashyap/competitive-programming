/*
Complexity Analysis
Time Complexity

Sorting:

O(n log n + m log m)

Two-pointer traversal:

O(n + m)

Overall:

O(n log n + m log m)
Space Complexity

Ignoring the input arrays:

O(1)

Including the arrays:

O(n + m)
*/

// #include<iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> boys(n);
    for (int i = 0; i < n; i++)
        cin >> boys[i];

    int m;
    cin >> m;

    vector<int> girls(m);
    for (int i = 0; i < m; i++)
        cin >> girls[i];

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int i = 0, j = 0;
    int ans = 0;

    while (i < n && j < m) {
        if (abs(boys[i] - girls[j]) <= 1) {
            ans++;
            i++;
            j++;
        }
        else if (boys[i] < girls[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    cout << ans << '\n';
}