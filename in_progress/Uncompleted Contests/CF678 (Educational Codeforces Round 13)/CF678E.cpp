/*
  DP[i][mask] where i is the current player alive and 
    mask indicated the players who have already fought.
  
  This means that all the 1s in mask that isn't player i are dead.
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

const int N = 18;
ld dp[N][1<<N];
bool vis[N][1<<N];

ld p[N][N];
int n;

ld solve(int idx, int mask){
  if ((mask&1) && idx != 0) return 0;
  if (mask == (1<<n)-1) return 1;
  if (vis[idx][mask]) return dp[idx][mask];
  ld &res = dp[idx][mask];

  res = 0;
  for (int i = 0; i < n; i++) {
    // Have not fought yet
    if (!((mask>>i)&1)) {
      res = max(res, p[idx][i]*solve(idx,mask|(1<<i)) + p[i][idx]*solve(i, mask|(1<<i)));
    } 
  }
  
  vis[idx][mask] = 1;
  return res; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }

  cout << setprecision(10) << fixed;
  memset(vis, 0, sizeof vis);
  memset(dp, 0, sizeof dp);

  ld ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, solve(i, 1<<i));
  }
  cout << ans << endl;
  
  return 0;
}
