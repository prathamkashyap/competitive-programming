#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  unordered_map<string, string> original;
  unordered_map<string, string> current;

  for (int i=0; i<n; i++) {
    string oldName, newName;
    cin >> oldName >> newName;

    string start;

    if (original.count(oldName)) {
      start = original[oldName];
    }
    else {
      start = oldName;
    }

    original.erase(oldName);
    original[newName] = start;
    current[start] = newName;
  }

  cout << current.size() << "\n";

  for (auto &entry : current) {
    cout << entry.first << " " << entry.second << "\n";
  }

  return 0;
}