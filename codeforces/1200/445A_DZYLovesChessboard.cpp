#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> board(n);

  for (int i=0; i<n; i++) {
    cin >> board[i];
  }

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (board[i][j] == '.') {
        if ((i+j) % 2 == 0)
          board[i][j] = 'B';
        else
          board[i][j] = 'W';
      }
    }
  }

  for (const string& row : board) {
    cout << row << '\n';
  }
  return 0;
}