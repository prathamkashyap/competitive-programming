#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> mp;

    while (n--) {
        string s;
        cin >> s;

        if (mp.find(s) == mp.end()) {
            cout << "OK\n";
            mp[s] = 1;
        } else {
            cout << s << mp[s] << '\n';
            mp[s]++;
        }
    }

    return 0;
}