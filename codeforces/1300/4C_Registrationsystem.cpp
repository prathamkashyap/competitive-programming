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


/* CAUSES TLE -> Time limit exceeded on test 7*/
// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     vector<string> users;

//     while (n--) {
//         string username;
//         cin >> username;

//         int count = 0;

//         for (const string &registered : users) {
//             if (registered == username) {
//                 count++;
//             }
//         }

//         if (count == 0) {
//             cout << "OK\n";
//         } else {
//             cout << username << count << '\n';
//         }

//         users.push_back(username);
//     }

//     return 0;
// }