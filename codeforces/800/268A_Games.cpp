// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n; 
//     cin >> n;
//     vector<pair<int,int>> teams(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> teams[i].first >> teams[i].second; // home, guest colors
//     }
    
//     int count = 0;
//     for (int host = 0; host < n; ++host) {
//         for (int guest = 0; guest < n; ++guest) {
//             if (host != guest && teams[host].first == teams[guest].second) {
//                 count++;
//             }
//         }
//     }
//     cout << count << '\n';
//     return 0;
// }


#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int home[30], guest[30];
    
    // Read uniform colors for each team
    for (int i = 0; i < n; i++) {
        cin >> home[i] >> guest[i];
    }
    
    int count = 0;
    
    // Check all possible games
    // For each team i (host) playing against team j (guest)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                // Host team wears guest uniform if their home color
                // matches the guest team's guest uniform color
                if (home[i] == guest[j]) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}

// Alternative optimized solution using frequency counting
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int home[30], guest[30];
    int guestFreq[101] = {0}; // Frequency of guest uniform colors
    
    for (int i = 0; i < n; i++) {
        cin >> home[i] >> guest[i];
        guestFreq[guest[i]]++;
    }
    
    int count = 0;
    
    // For each team, count how many teams have guest uniform
    // matching this team's home uniform
    for (int i = 0; i < n; i++) {
        count += guestFreq[home[i]];
    }
    
    cout << count << endl;
    
    return 0;
}
*/