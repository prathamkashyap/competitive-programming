// #include <iostream>
// #include <vector>

// using namespace std;

// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int multTestQ;
//     cin >> multTestQ;

//     while (multTestQ--) {
//         int n;
//         cin >> n;

//         ll totalCards = 0;
//         int oddCount = 0;

//         for (int i = 0; i < n; i++) {
//             ll count;
//             cin >> count;

//             totalCards += count;

//             if (count % 2 == 1)
//                 oddCount++;
//         }

//         ll answer;

//         if (oddCount == 0)
//             answer = totalCards;
//         else
//             answer = totalCards - oddCount + 1;

//         if (answer < 3)
//             answer = 0;

//         cout << answer << '\n';
//     }

//     return 0;
// }

#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int multTestQ;
    cin >> multTestQ;

    while (multTestQ--) {
        int n;
        cin >> n;

        ll totalCards = 0;
        ll singleCards = 0;
        ll availableSlots = 0;

        for (int i = 0; i < n; i++) {
            ll count;
            cin >> count;

            totalCards += count;

            if (count == 1)
                singleCards++;
            else
                availableSlots += count / 2 - 1;
        }

        if (singleCards == n - 1)
            availableSlots++;

        ll discarded = max(0LL, singleCards - availableSlots);
        ll answer = totalCards - discarded;

        if (answer < 3)
            answer = 0;

        cout << answer << '\n';
    }

    return 0;
}