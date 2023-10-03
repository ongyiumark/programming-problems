/*
  DP where DP[i][j] counts the number of pairs until s[i] and t[j].
  If s[i] != t[j], DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1].
  If s[i] == t[j], then we must count DP[i-1][j-1] twice. Hence, DP[i][j] = DP[i-1][j] + DP[i][j-1].

  Be careful of negative numbers when modding.
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

const int N = 2e3+5;
const int MOD = 1e9+7;
int n, m;
int s[N], t[N];
ll dp[N][N];

ll solve(int i, int j){
  ll &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = 0;

  if (i == 0 || j == 0) {
    return ans = 1;
  }

  ans = solve(i-1, j) + solve(i, j-1) - solve(i-1,j-1);
  if (s[i-1] == t[j-1]) ans += solve(i-1, j-1);
  ans %= MOD;
  if (ans < 0) ans += MOD;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int j = 0; j < m; j++) cin >> t[j];

  memset(dp, -1, sizeof dp);
  cout << solve(n,m) << endl;
  return 0;
}
