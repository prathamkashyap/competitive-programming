#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  string s;
  cin >> s;

  /*
  // APPROACH 1 {First Time Thinking}
  vector<int> charList(26);

  for (char ch : s) {
    charList[ch - 'a'] = 1;
  }A. Collatz Conjecture

  int distinctCount = 0;
  for (int i=0; i<26; i++) {
    distinctCount += charList[i];
  }

  if (distinctCount %2 == 0)
    cout << "CHAT WITH HER!" << endl;
  else
    cout << "IGNORE HIM!" << endl;
  */

  // APPROACH 2 {USING SET}
  set<char> st(s.begin(), s.end());

  if (st.size() % 2 == 0)
    cout << "CHAT WITH HER!\n";
  else
    cout << "IGNORE HIM!\n";

}