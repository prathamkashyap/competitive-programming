// Idea

// We need to check whether:

// guest + host

// contains exactly the same letters as the third string.

// Order does not matter, but frequency does.

// Approach 1 (Recommended): Frequency Array

// Since there are only 26 uppercase English letters, use a frequency array.

// Count every character in the guest's name.
// Count every character in the host's name.
// Remove every character found in the pile.
// If every frequency becomes 0, print "YES", otherwise "NO".
// Complexity
// Time: O(n)
// Space: O(26) = O(1)

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string guest, host, pile;
    cin >> guest >> host >> pile;

    int freq[26] = {};

    for (char c : guest)
        freq[c - 'A']++;

    for (char c : host)
        freq[c - 'A']++;

    for (char c : pile)
        freq[c - 'A']--;

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}

// Approach 2 (Even Simpler)
// Concatenate the first two strings, sort both strings, and compare them.

// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string guest, host, pile;
//     cin >> guest >> host >> pile;

//     string names = guest + host;

//     sort(names.begin(), names.end());
//     sort(pile.begin(), pile.end());

//     cout << (names == pile ? "YES" : "NO") << '\n';

//     return 0;
// }

// This solution is also accepted and is very concise, though the frequency-array approach is slightly more efficient (O(n) vs. O(n log n)).