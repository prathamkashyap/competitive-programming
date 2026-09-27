#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
  int N;
  cin >> N;

  vector<int> a(N);

  for (int i=0; i<N; i++) {
    cin >> a[i];
  }

  const int INF = 1e9;

  int rest = 0;
  int contest = INF;
  int gym = INF;

  for (int i=0; i<N; i++) {
    int newRest = min({rest, contest, gym}) + 1;
    int newContest = INF;
    int newGym = INF;

    if (a[i] == 1 || a[i] == 3) {
      newContest = min(rest, gym);
    }

    if (a[i] == 2 || a[i] == 3) {
      newGym = min(rest, contest);
    }

    rest = newRest;
    contest = newContest;
    gym = newGym;
  }

  return min({rest, contest, gym});
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << solve() << '\n';

  return 0;
}