#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;

void solve()
{
  int n;
  ll d;
  cin >> n >> d;

  vector<pair<ll, ll>> friends(n);

  for (int i = 0; i < n; i++)
  {
    cin >> friends[i].first >> friends[i].second;
  }

  sort(friends.begin(), friends.end());

  ll currentSum = 0;
  ll answer = 0;

  int left = 0;

  for (int right = 0; right < n; right++)
  {
    currentSum += friends[right].second;

    while (left <= right &&
           friends[right].first - friends[left].first >= d)
    {
      currentSum -= friends[left].second;
      left++;
    }

    answer = max(answer, currentSum);
  }

  cout << answer << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}