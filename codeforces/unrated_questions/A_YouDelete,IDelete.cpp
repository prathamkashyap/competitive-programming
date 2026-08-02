#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    string optimallyA = "";

    for (int i=0; i<s.size(); i++) {
      if (s[i] != '0')
        continue;

      string endA = s;
      endA.erase(i,1);

      string optimallyB = "";

      bool check = true;

      int sizeA = endA.size();

      for (int j=0; j<sizeA; j++) {
        if (endA[j] != '1') 
          continue;

        string endB = endA;
        endB.erase(j, 1);

        if (check || endB < optimallyB) {
            optimallyB = endB;
            check = false;
        }
      }

      if (optimallyA.empty() || optimallyB > optimallyA)
          optimallyA = optimallyB;
    }
      cout << optimallyA << '\n';
    }
  return 0;
}