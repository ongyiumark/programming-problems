/*
  We can solve this with a min DP on the cost with bitmask.
  DP[j][mask] is the cost of getting a stick of length j using the sticks in the bits of mask.
  
  Then, the answer is the min of DP[a][amask] + DP[b][bmask] + DP[c][cmask]
    where amask, bmask, and cmask share no bits in common.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int l[10];
int n;
const int N = 1005;
const int INF = 1e9;

// DP[j][mask] is the cost of getting length j using the sticks in the mask.
int dp[N][256];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int a, b, c; cin >> a >> b >> c;
  for (int i = 0; i < n; i++) cin >> l[i];

  memset(dp, 63, sizeof dp);
  for (int i = 0; i < n; i++){
    int mask = (1<<i);
    for (int j = 0; j < N; j++){
      dp[j][mask] = abs(l[i]-j);
    }
    for (int m = 1; m < (1<<n); m++){
      if (m&mask) continue;
      for (int j = 0; j < N; j++){
        if (dp[j][m] >= INF) continue;
        if (j + l[i] >= N) continue;
        dp[j+l[i]][mask|m] = min(dp[j+l[i]][mask|m], dp[j][m]+10); 
      }
    }  
  }

  int ans = INF;
  for (int i = 1; i < (1<<n); i++){
    if (dp[a][i] >= INF) continue;
    for (int j = 1; j < (1<<n); j++){
      if (i&j) continue;
      if (dp[b][j] >= INF) continue;
      for (int k = 1; k < (1<<n); k++){
        if (i&k) continue;
        if (j&k) continue;
        if (dp[c][k] >= INF) continue;
        ans = min(ans, dp[a][i]+dp[b][j]+dp[c][k]);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
