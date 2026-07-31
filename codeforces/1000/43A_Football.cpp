// #include <iostream>
// #include <string>
// #include <map>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     map<string, int> cnt;

//     string team, ans;
//     int mx = 0;

//     while (n--) {
//         cin >> team;
//         cnt[team]++;

//         if (cnt[team] > mx) {
//             mx = cnt[team];
//             ans = team;
//         }
//     }

//     cout << ans << '\n';

//     return 0;
// }

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string first, team;
    cin >> first;

    int firstCnt = 1;
    string second;
    int secondCnt = 0;

    for (int i = 1; i < n; i++) {
        cin >> team;

        if (team == first)
            firstCnt++;
        else {
            second = team;
            secondCnt++;
        }
    }

    cout << (firstCnt > secondCnt ? first : second) << '\n';

    return 0;
}