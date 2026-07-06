#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> prefixBalance(n);
    int balance = 0;
    for (int i = 0; i < n; i++) {
        prefixBalance[i] = balance;
        if (s[i] == '(') balance++;
        else balance--;
    }

    vector<tuple<int,int,char>> arr;
    for (int i = 0; i < n; i++) {
        arr.emplace_back(prefixBalance[i], -i, s[i]);
    }

    sort(arr.begin(), arr.end());

    for (auto &t : arr) {
        cout << get<2>(t);
    }
    cout << "\n";

    return 0;
}

