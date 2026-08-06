#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  
  while (t--) {
    int n;
    cin >> n;

    vector<int> spellCards(n);
    unordered_map<int, int> freq;

    int totalDamage = 0;

    for (int i=0; i<n; i++) {
      cin >> spellCards[i];
      totalDamage += spellCards[i];
      freq[spellCards[i]]++;
    }

    int maxFrequency = 0;
    int maxDamage = 0;

    for (auto [damage, count] : freq) {
      if (count > maxFrequency) {
        maxFrequency = count;
        maxDamage = damage;
      }
    }

    int otherCards = n - maxFrequency;
    if (maxFrequency <= otherCards + 1) {
      cout << totalDamage << '\n';
    }
    else {
      int answer = totalDamage - maxFrequency * maxDamage;
      answer += (otherCards + 2) * maxDamage;
      cout << answer << '\n';
    }
  }

  return 0;
}