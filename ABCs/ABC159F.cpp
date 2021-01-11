/*
  (L, x1, x2, ..., R)
  DP[i][s][t] on combinations of the first i elements that sum to s.
  t represents the type: (1) no L, (2) just L, (3) L and R.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 3001;
const ll MOD = 998244353;
ll A[N];
ll dp[N][N][3];


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s; cin >> n >> s;
  for (int i = 0; i < n; i++) cin >> A[i];

  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= s; j++){
      dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0]) % MOD;
      dp[i+1][j][1] = (dp[i+1][j][1] + dp[i][j][1] + dp[i][j][0]) % MOD;
      dp[i+1][j][2] = (dp[i+1][j][2] + dp[i][j][2] + dp[i][j][1] + dp[i][j][0]) % MOD;

      if (j + A[i] <= s){
        dp[i+1][j+A[i]][1] = (dp[i+1][j+A[i]][1] + dp[i][j][1] + dp[i][j][0]) % MOD;
        dp[i+1][j+A[i]][2] = (dp[i+1][j+A[i]][2] + dp[i][j][1] + dp[i][j][0]) % MOD;
      }
    }
  }
  cout << dp[n][s][2] << endl;

  return 0;
}
