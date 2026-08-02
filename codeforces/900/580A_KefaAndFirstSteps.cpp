// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
    
//     int prev;
//     cin >> prev;
    
//     int currentLength = 1;
//     int maxLength = 1;
    
//     for (int i = 1; i < n; i++) {
//         int curr;
//         cin >> curr;
        
//         if (curr >= prev) {
//             currentLength++;
//             maxLength = max(maxLength, currentLength);
//         } else {
//             currentLength = 1;
//         }
        
//         prev = curr;
//     }
    
//     cout << maxLength << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int current = 1;
    int best = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1])
            current++;
        else
            current = 1;

        best = max(best, current);
    }

    cout << best << '\n';

    return 0;
}