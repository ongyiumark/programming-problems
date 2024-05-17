#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1e18;
int main() {
  cin.tie(0)->sync_with_stdio(false);

  int n; cin >> n;
  vector<int> A(n), B(n);
  for (int &x : A) cin >> x;
  for (int &x : B) cin >> x;

  int m = 10*n;
  vector<vector<ll>> memo(n, vector<ll>(m, -1));
  function<ll(int, int)> solve = [&](int i, int j) {
    if (i < 0 || j < 0) return INF;
    ll &ans = memo[i][j];
    if (ans != -1) return ans;
    if (i == 0) return ans = (j != B[0]) ? INF : j+A[i];

    ans = max((ll)j, min(solve(i-1, j-B[i]), solve(i-2, j-B[i])+A[i-1])) + A[i];
    return ans;
  };

  ll ans = INF;
  for (int j = 0; j < m; j++) {
    ans = min(ans, solve(n-1, j));
  }
  cout << ans << "\n";

  return 0;
}