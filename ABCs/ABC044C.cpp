/*
  DP where dp[i][j][k] is the number of ways a selection of j from the first i numbers have a sum of k.
  dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i]]

  The answer is the sum of dp[N][x][A*x] for 1 <= x <= N. 
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 51;
int x[N];

ll dp[N][N][N*N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a; cin >> n >> a;
  for (int i = 1; i <= n; i++){
    cin >> x[i];
  }

  memset(dp, 0, sizeof dp);
  
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= i; j++){
      dp[i][j][0] = 1;
    }
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= i; j++){
      for (int k = 0; k <= j*50; k++){
        dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i]]*(k >= x[i]);
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) ans += dp[n][i][a*i];
  cout << ans << endl;
  return 0;
}
