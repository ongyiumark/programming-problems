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

const ll MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  // num of addends, sum
  ll ways[8][8];
  memset(ways, 0, sizeof ways);
  ways[0][0] = 1;
  for (int i = 0; i <= 7; i++) {
    for (int d = 1; d <= 10; d++) {
      if (i+d > 7) continue;
      for (int j = 1; j <= 7; j++) {
        ways[j][i+d] += ways[j-1][i];
      }
    }
  }

  // powers of 10
  ll pow10[50];
  pow10[0] = 1;
  for (int i = 1; i < 50; i++) pow10[i] = pow10[i-1]*10%MOD;

  int n, x, y, z; cin >> n >> x >> y >> z;
  ll dp[n+1];
  memset(dp, 0, sizeof dp);
  for (int cn = 1; cn <= n; cn++) {
    ll ans = 0;
    for (int i = 1; i <= x; i++) {
      for (int j = 1; j <= y; j++) {
        for (int k = 1; k <= z; k++) {
          if (i+j+k > cn) continue;
          int excess = cn-i-j-k;
          for (int l = 0; l <= excess; l++) {
            ll w = ways[i][x]*ways[j][y]*ways[k][z]%MOD;
            w = w*(pow10[l]-dp[l])%MOD*(pow10[excess-l]-dp[excess-l])%MOD;
            ans += w;
            ans %= MOD;
          }
          //ans %= MOD;
        }
      }
    }
    if (ans < 0) ans += MOD;
    dp[cn] = ans;
    cout << cn << " " << dp[cn] << endl;
  }
  
  cout << dp[n] << endl;
  return 0;
}
