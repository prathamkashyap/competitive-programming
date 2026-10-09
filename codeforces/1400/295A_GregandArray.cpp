#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, K;
  cin >> N >> M >> K;
  
  vector<ll> a(N+2, 0);

  for (int i=1; i<=N; i++) {
    cin >> a[i];
  }

  vector<int> l(M+1), r(M+1);
  vector<ll> d(M+1);

  for (int i=1; i<=M; i++) {
    cin >> l[i] >> r[i] >> d[i];
  }

  vector<ll> opDiff(M+2, 0);

  for (int i=1; i<=K; i++) {
    int x,y;
    cin >> x >> y;

    opDiff[x]++;
    opDiff[y+1]--;
  }

  vector<ll> opCount(M+1, 0);
  ll currentCount = 0;

  for (int i = 1; i <= M; i++) {
        currentCount += opDiff[i];
        opCount[i] = currentCount;
    }

    vector<long long> arrDiff(N + 2, 0);

    for (int i = 1; i <= M; i++) {
        long long value = d[i] * opCount[i];

        arrDiff[l[i]] += value;
        arrDiff[r[i] + 1] -= value;
    }

    long long currentAdd = 0;

    for (int i = 1; i <= N; i++) {
        currentAdd += arrDiff[i];
        cout << a[i] + currentAdd << (i == N ? '\n' : ' ');
    }

    return 0;
}
