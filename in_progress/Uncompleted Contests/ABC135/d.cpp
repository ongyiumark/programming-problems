#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
const ll MOD = 1e9+7;

int main(){
  cin.tie(0)->sync_with_stdio(false);

  string s; cin >> s;
  int n = s.size();

  ll dp[n+1][13];
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 13; j++) {
      if (s[i-1] != '?') {
        int nj = (10*j+s[i-1]-'0')%13;
        dp[i][nj] = (dp[i][nj] + dp[i-1][j])%MOD;
        continue;
      }

      for (int jj = 0; jj <= 9; jj++) {
        int nj = (10*j+jj)%13;
        dp[i][nj] = (dp[i][nj] + dp[i-1][j])%MOD;
      }
    }
  }
  cout << dp[n][5] << "\n";
  
  return 0;
}
