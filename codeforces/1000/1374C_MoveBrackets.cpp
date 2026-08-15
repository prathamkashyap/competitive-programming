#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;

    cin >> n >> s;

    int balance = 0;
    int answer = 0;

    for (char c : s) {
      if (c == '(') 
        balance++;
      else
        balance--;
      
      if (balance < 0) {
        answer++;
        balance = 0;
      }
    }

    cout << answer << '\n';
  }
  return 0;
}