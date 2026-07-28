#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
  int n;
  long long t;
  cin >> n >> t;

  vector<int> books(n);

  for (int i = 0; i < n; i++) {
    cin >> books[i];
  }

  int left = 0;
  long long currentSum = 0;
  int answer = 0;

  for (int right = 0; right < n; right++) {
    currentSum += books[right];

    while (left <= right && currentSum > t) {
      currentSum -= books[left];
      left++;
    }

    answer = max(answer, right - left + 1);
  }

  cout << answer << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}