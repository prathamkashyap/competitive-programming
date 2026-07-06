#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string word;
    cin >> word;
    
    int n = word.length();
    
    // Check if all letters are uppercase
    bool allUpper = true;
    for (int i = 0; i < n; i++) {
        if (islower(word[i])) {
            allUpper = false;
            break;
        }
    }
    
    // Check if all letters except first are uppercase
    bool allExceptFirstUpper = true;
    for (int i = 1; i < n; i++) {
        if (islower(word[i])) {
            allExceptFirstUpper = false;
            break;
        }
    }
    
    // Apply the rule if either condition is met
    if (allUpper || allExceptFirstUpper) {
        for (int i = 0; i < n; i++) {
            if (isupper(word[i])) {
                word[i] = tolower(word[i]);
            } else {
                word[i] = toupper(word[i]);
            }
        }
    }
    
    cout << word << endl;
    
    return 0;
}