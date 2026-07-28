#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
  int n, m; 
  cin >> n >> m;

  vector<int> a(n+1);
  vector<int> suffixDistinct(n+2);

  for (int i=1; i<=n; i++) {
    cin >> a[i];
  }

  set<int> st;

  for (int i=n; i>=1; i--) {
    st.insert(a[i]);
    suffixDistinct[i] = st.size();
  }

  while (m--) {
    int l;
    cin >> l;
    cout << suffixDistinct[l] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}