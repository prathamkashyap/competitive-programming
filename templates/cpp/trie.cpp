#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool is_end;
    
    TrieNode() {
        memset(children, 0, sizeof(children));
        is_end = false;
    }
};

class Trie {
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string s) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->is_end = true;
    }
    
    bool search(string s) {
        TrieNode* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Trie trie;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string op, s;
        cin >> op >> s;
        if (op == "insert") {
            trie.insert(s);
        } else if (op == "search") {
            cout << (trie.search(s) ? "Yes" : "No") << '\n';
        }
    }
    
    return 0;
}
