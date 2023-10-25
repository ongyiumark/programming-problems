#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k; cin >> n >> k;
  vector<ld> p(n);
  for (ld &x : p) cin >> x;
  sort(p.begin(), p.end(), greater<ld>());

  ld ans = 0;
  vector dp(2, vector<ld>(2*n+1));
  vector<ld>& prevdp = dp[0];
  vector<ld>& nextdp = dp[1];
  prevdp[0+n] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = -n; j <= n; j++) {
      int jj = j+n;
      nextdp[jj] = 0;
      if (jj-1 >= 0) nextdp[jj] += prevdp[jj-1]*p[i];
      if (jj+1 < 2*n+1) nextdp[jj] += prevdp[jj+1]*(1-p[i]);
    }
    ld tmp = 0;
    for (int j = k; j <= n; j++) tmp += nextdp[j+n];
    ans = max(ans, tmp);
    swap(prevdp, nextdp);
  }
  cout << ans << "\n";

  return 0;
}