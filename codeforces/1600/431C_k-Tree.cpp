#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, d;
  cin >> n >> k >> d;

  vector<vector<int>> dp(n+1, vector<int>(2,0));

  dp[0][0] = 1;

  for (int i=1; i<=n; i++) {
    for (int jump = 1; jump <= k && jump <= i; jump++) {
      if (jump < d) {
        dp[i][0] = (dp[i][0] + dp[i - jump][0]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - jump][1]) % MOD;
      }
      else {
        dp[i][1] = (dp[i][1] + dp[i-jump][0]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i-jump][1]) % MOD;
      }
    }
  }

  cout << dp[n][1] << '\n';
  return 0;
}