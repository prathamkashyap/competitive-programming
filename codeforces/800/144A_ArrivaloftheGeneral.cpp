#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> heights(n);
    for (int i = 0; i < n; ++i)
        cin >> heights[i];

    int maxHeight = *max_element(heights.begin(), heights.end());
    int minHeight = *min_element(heights.begin(), heights.end());

    int maxIndex = distance(heights.begin(), find(heights.begin(), heights.end(), maxHeight));
    int minIndex = distance(heights.rbegin(), find(heights.rbegin(), heights.rend(), minHeight));
    minIndex = n - 1 - minIndex;

    int swaps = maxIndex + (n - 1 - minIndex);
    if (maxIndex > minIndex) swaps--;

    cout << swaps << '\n';
    return 0;
}
