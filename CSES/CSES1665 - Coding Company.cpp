#include <bits/stdc++.h>
using namespace std;


const int MAXN = 100;
const int MAXS = 2*MAXN*MAXN+1;
const int MOD = 1e9+7;
int dp[2][MAXN+1][MAXS];


int main() {
  cin.tie(0)->sync_with_stdio(false);
  memset(dp, 0, sizeof dp);

  int n, x; 
  cin >> n >> x;
  vector<int> t(n);
  for (int &tt : t) cin >> tt;
  sort(t.begin(), t.end());
  
  int T = accumulate(t.begin(), t.end(), 0);
  vector<int> pref(n);
  pref[0] = t[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i-1]+t[i];
  }

  dp[0][0][T] = 1;
  for (int i = 1; i <= n; i++) {
    memset(dp[i%2], 0, sizeof dp[i%2]);
    for (int j = 0; j <= i; j++) {
      for (int k = T-pref[i-1]; k <= T+pref[i-1]; k++) {
        int current = dp[(i-1)%2][j][k];
        if (current == 0) continue;

        if (j+1 <= n && k-t[i-1] >= 0) {
          dp[i%2][j+1][k-t[i-1]] += current; // start new team with t[i]
          dp[i%2][j+1][k-t[i-1]] %= MOD;
        }

        dp[i%2][j][k] += (long long)(j+1)*current%MOD; // continue team with t[i] or start and end a new team with just t[i]
        dp[i%2][j][k] %= MOD;

        if (j-1 >= 0 && k+t[i-1] <= 2*T) {
          dp[i%2][j-1][k+t[i-1]] += (long long)j*current%MOD; // close team with t[i]
          dp[i%2][j-1][k+t[i-1]] %= MOD;
        }
      }
    }
  }


  int ans = 0;
  for (int k = T; k <= T+x; k++) {
    ans += dp[n%2][0][k];
    ans %= MOD;
  }
  cout << ans << "\n";

  return 0;
}