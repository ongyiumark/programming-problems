/*
  Let dp[i][j] be the number of groups of size <= i with j people.

  The following reccurence is true:
  dp[i][j] = dp[i-1][j] + (for k in c to d, comb(j, k*i)*group(i, k)*dp[i-1][j-i*k])

  First we pick k*i people from the set of j people: comb(j, k*i).
  Then we group those k*i people into k groups of i: group(i,k).
    This can be solved with another dp.
  Finally, we group the remaining people with groups of sizes <= i-1.
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

const int N = 1e3+5;
const ll MOD = 1e9+7;

int n, a, b, c, d;
ll dp[N][N], helper_dp[N][N], comb[N][N];

ll fastpow(ll b, ll e){
  ll ans = 1;
  while(e > 0){
    if (e&1) ans = ans*b%MOD;
    b = b*b%MOD;
    e >>= 1;
  }
  return ans;
}

ll inv(ll x){
  return fastpow(x, MOD-2);
}

ll groups(int i, int k){
  ll &ret = helper_dp[i][k];
  if (ret != -1) return ret;
  if (k == 0) return ret = 1;
  ret = comb[i*k][i]*groups(i, k-1)%MOD*inv(k)%MOD;
  return ret;
}

ll solve(int i, int j){
  ll &ret = dp[i][j];
  if (ret != -1) return ret;
  if (j == 0) return ret = 1;
  if (i < a) return ret = 0;
  
  ret = solve(i-1,j);
  for (int k = c; k <= d && i*k <= j; k++){
    ll curr = (solve(i-1, j-i*k)*comb[j][i*k]%MOD)*groups(i, k)%MOD;
    ret += curr;
    ret %= MOD;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(dp, -1, sizeof dp);
  memset(helper_dp, -1, sizeof helper_dp);
  memset(comb, 0, sizeof comb);
  for (int i = 0; i < N; i++){
    for (int j = 0; j <= i; j++){
      if (i == 0 || j == 0) comb[i][j] = 1;
      else comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%MOD;
    }
  }
  cin >> n >> a >> b >> c >> d;
  cout << solve(b, n) << endl;
  return 0;
}
