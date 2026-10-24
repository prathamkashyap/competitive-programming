#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void kmp_search(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    vector<int> pi = prefix_function(pattern);
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j-1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - m + 1 << '\n';
            j = pi[j-1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string text, pattern;
    cin >> text >> pattern;
    
    kmp_search(text, pattern);
    
    return 0;
}
