/*
  Let dp[i][j] be the number of trains that start on or before i but end on or before j.
  Then, the answer of quert p, q is simply dp[q][q] - dp[p-1][q].

  Let x[i][j] be the number of trains that start at i and end at j.
  dp[i][j] = x[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1].
  We subtract that last component because we count it twice.
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

const int N = 505;
int dp[N][N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q; cin >> n >> m >> q;
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < m; i++){
    int l, r; cin >> l >> r;
    dp[l][r]++;
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
    }
  }

  for (int i = 0; i < q; i++){
    int a, b; cin >> a >> b;
    cout << dp[b][b] - dp[a-1][b] << endl;
  }
  return 0;
}
