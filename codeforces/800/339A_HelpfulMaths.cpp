#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string nums;
    for (char c : s) {
        if (c >= '1' && c <= '3') {
            nums.push_back(c);
        }
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < (int)nums.size(); i++) {
        cout << nums[i];
        if (i != (int)nums.size() - 1) {
            cout << "+";
        }
    }
    cout << "\n";
    return 0;
}
