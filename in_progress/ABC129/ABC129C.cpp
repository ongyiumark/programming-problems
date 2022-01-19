/*
  Do DP[i] = DP[i-1] + DP[i-2].s
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

const int N = 1e5+5;
const int MOD = 1e9+7;
int dp[N];
bool broken[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  memset(broken, 0, sizeof broken);
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    broken[x] = 1;
  }
  dp[0] = 1;
  for (int i = 1; i <= n; i++){
    if (broken[i]) continue;
    if (i == 1) dp[i] += dp[i-1];
    else dp[i] += dp[i-1] + dp[i-2];
    dp[i] %= MOD;
  }

  cout << dp[n] << endl;
  return 0;
}
