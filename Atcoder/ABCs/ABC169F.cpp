#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 998244353;

const int N = 3001;
ll arr[N];

ll dp[N][N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, s; cin >> n >> s;
  for (int i = 0; i < n; i++){
    cin >> arr[i];
  }

  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= s; j++){
      dp[i+1][j] = (dp[i+1][j] + 2*dp[i][j])%MOD;
      if (j + arr[i] > s) continue;
      dp[i+1][j + arr[i]] = (dp[i+1][j + arr[i]] + dp[i][j])%MOD;
    }
  }

  cout << dp[n][s] << endl;
  return 0;
}
