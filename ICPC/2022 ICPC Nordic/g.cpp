#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k; cin >> n >> k;
  vector<ld> p(n);
  for (auto &x: p) cin >> x;
  
  vector<vector<ld>> dp(2, vector<ld>(2*n+1));
  sort(p.rbegin(), p.rend());
  dp[0][n] = 1;
  ld best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2*n+1; j++) {
      ld answered = 0;
      if (j-1 >= 0) answered += dp[i%2][j-1]*p[i];
      if (j+1 < 2*n+1) answered += dp[i%2][j+1]*(1-p[i]);

      dp[(i+1)%2][j] = answered;
    }
    ld total = 0;
    for (int j = n+k; j < 2*n+1; j++) total += dp[(i+1)%2][j];
    best = max(total, best);
  }
  cout << best << "\n";

  return 0;
}