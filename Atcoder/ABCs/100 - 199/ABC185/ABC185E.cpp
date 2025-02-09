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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  int dp[n+1][m+1];
  int A[n], B[m];
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int j = 0; j < m; j++) cin >> B[j];

  memset(dp, 0, sizeof dp);
  for (int i = 1; i <= n; i++) dp[i][0] = i;
  for (int j = 1; j <= m; j++) dp[0][j] = j;
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (A[i-1] != B[j-1]) dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
      else dp[i][j] = dp[i-1][j-1];
    }
  }

  cout << dp[n][m] << "\n";
  
  return 0;
}
