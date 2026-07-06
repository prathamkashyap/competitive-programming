#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string word;
    cin >> word;

    int upperCount = count_if(word.begin(), word.end(), [](char c){ return isupper(c); });
    if (upperCount > (int)word.size() / 2) {
        transform(word.begin(), word.end(), word.begin(), ::toupper);
    } else {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
    }

    cout << word << "\n";
    return 0;
}


// // Approach 2
// #include<iostream>
// #include<string>
// #include<cctype>
// using namespace std;

// int main(){
//   string word;
//   cin >> word;
  
//   int upperCount = 0, lowerCount = 0;
//   for (char c : word) {
//     if (isupper(c)) upperCount++;
//     else lowerCount++;
//   }

//   if (upperCount > lowerCount) {
//     for (char &c : word) c = toupper(c);
//   }
//   else {
//     for (char &c : word) c = tolower(c);
//   }

//   cout << word << "\n";
//   return 0;
// }